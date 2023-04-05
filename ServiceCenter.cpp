#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <iostream>

ServiceCenter::ServiceCenter(){
    m_clockTick = 1;
}

ServiceCenter::ServiceCenter(std::string inFile){
    m_clockTick = 1;
    m_tickInfo = new TickInfo();
    processFile(inFile);
    
}

ServiceCenter::~ServiceCenter(){
    std::string finalString;
    finalString = "Number of students waiting over 10 minutes across all offices: " + std::to_string(getStudentsWaitingOverTen()) + "\n";
    finalString += "Number of windows idle for over 5 minutes across all offices: " + std::to_string(getWindowsIdleOverFive()) + "\n";
    // std::cout << "Number of students waiting over 10 minutes across all offices: " << getStudentsWaitingOverTen() << std::endl;
    // std::cout << "Number of windows idle for over 5 minutes across all offices: " << getWindowsIdleOverFive() << std::endl;
    delete m_tickInfo;
    delete m_cashier;
    delete m_financial;
    delete m_registrar;
    std::cout << finalString << std::endl;
}

int ServiceCenter::getStudentsWaitingOverTen(){
    return m_registrar->getStudentsWaitingOverTen() + m_cashier->getStudentsWaitingOverTen() + m_financial->getStudentsWaitingOverTen();
}

int ServiceCenter::getWindowsIdleOverFive(){
    return m_registrar->getWindowsIdleOverFive() + m_cashier->getWindowsIdleOverFive() + m_financial->getWindowsIdleOverFive();
}

void ServiceCenter::serviceCenterSimulation(){
    std::cout << " Eneter Simulation" << std::endl;
    advanceTick();
    // std::cout << !m_tickInfo->m_customerQueue->isEmpty() << std::endl;
    // std::cout << !(m_cashier->isWindowsEmpty() || m_registrar->isWindowsEmpty() || m_financial->isWindowsEmpty()) << std::endl;
    // std::cout << (!m_cashier->m_officeQueue->isEmpty() && !m_registrar->m_officeQueue->isEmpty() && !m_financial->m_officeQueue->isEmpty()) << std::endl;
    // std::cout << (!m_cashier->m_leavingQueue->isEmpty() && !m_registrar->m_leavingQueue->isEmpty() && !m_financial->m_leavingQueue->isEmpty()) << std::endl;
    while (m_clockTick != 20){
        std::cout << " entered while loop" << std::endl;
        std::cout << "clock tick: " << m_clockTick << std::endl;
        advanceTick();
    }

}

bool ServiceCenter::isGameOver(){
    return (!m_tickInfo->m_customerQueue->isEmpty());
    // !(m_cashier->isWindowsEmpty() || m_registrar->isWindowsEmpty() || m_financial->isWindowsEmpty()) &&
    // !m_cashier->m_officeQueue->isEmpty() && !m_registrar->m_officeQueue->isEmpty() && !m_financial->m_officeQueue->isEmpty());
    //!m_cashier->m_leavingQueue->isEmpty() && !m_registrar->m_leavingQueue->isEmpty() && !m_financial->m_leavingQueue->isEmpty());
}

void ServiceCenter::processFile(std::string inFile){
    std::ifstream reader;
    std::string line;
    reader.open(inFile);

    int R_windowNum;
    int C_windowNum;
    int F_windowNum;
    int arriveTime;
    int studentNum;
    int lineCount = 1;
    int tmpLineCount;

    while (getline(reader,line)){
        if (line[0] == 'E'){
            break;
        }
        switch(lineCount){
            case 1:
                R_windowNum = stoi(line);
                break;
            case 2:
                C_windowNum = stoi(line);
                break;
            case 3:
                F_windowNum = stoi(line);
                break;
            case 4:
                arriveTime = stoi(line);
                break;
            case 5:
                studentNum = stoi(line);
                break;
            case 6: 
                std::cout << R_windowNum << " is R window \n" << C_windowNum << " is C window \n" << F_windowNum << " is F window \n";
                std::cout << arriveTime << " is arrive time \n" << studentNum << " is studetn num " << std::endl;
                for (int i = 0; i < studentNum; ++i){
                    Customer* customer = collectStudentInfo(line, arriveTime);      // makes customer
                    std::cout << "adding customer" << std::endl;
                    customer->printInfo();
                    m_tickInfo->addToCustomerQ(customer);                           // adds to queue 

                    if (i != studentNum - 1){
                        getline(reader, line);   // gets line for next student
                        ++lineCount;
                    }
                }
                break;
            default:
                if (lineCount == 6 + studentNum){    // line after student wait values
                    std::cout << lineCount << " is lineCount here" << std::endl;
                    arriveTime = stoi(line);
                    std::cout << arriveTime << " is new Arrive time" << std::endl;
                } else if (lineCount == 7 + studentNum){
                    tmpLineCount = 7 + studentNum; // saves line because studentNum gets reassigned
                    studentNum = stoi(line);
                    std::cout << studentNum << " is new student num" << std::endl;
                } else if (lineCount == tmpLineCount + 1){
                    for (int i = 0; i < studentNum; ++i){
                        Customer* customer = collectStudentInfo(line, arriveTime);
                        std::cout << "adding customer" << std::endl;
                        customer->printInfo();
                        m_tickInfo->addToCustomerQ(customer);

                        // do something with the collected values for that one student

                        if (i != studentNum - 1){
                            getline(reader, line);   // gets line for next student
                            ++lineCount;
                        }
                    }
                }
                break;
        }
        ++lineCount;
        // std::cout << lineCount << " is current Line Count" << std::endl;

        
    }

    makeOffices(R_windowNum, C_windowNum, F_windowNum);
}

char ServiceCenter::getOfficeChar(std::string value){
    if (value[0] == 'C'){
        return 'C';
    } else if (value[0] == 'R'){
        return 'R';
    } else if (value[0] == 'F'){
        return 'F';
    }
}

Customer* ServiceCenter::collectStudentInfo(std::string line, int arriveTime){
    Customer* customer;
    std::stringstream ss(line);
    std::string value;
    ListQueue<char>* m_officeOrder = new ListQueue<char>();
    ListQueue<int>* m_officeTimes = new ListQueue<int>();
    int valueCount = 1;
    while (ss >> value){
        switch(valueCount){
            case 1:
                m_officeTimes->add(stoi(value));
                break;
            case 2:
                m_officeTimes->add(stoi(value));
                break;
            case 3:
                m_officeTimes->add(stoi(value));
                break;
            case 4:
                m_officeOrder->add(getOfficeChar(value));
                break;
            case 5:
                m_officeOrder->add(getOfficeChar(value));
                break;
            case 6:
                m_officeOrder->add(getOfficeChar(value));
                break;
            default:
                break;
        }
        ++valueCount;
    }

    customer = new Customer(arriveTime, m_officeOrder, m_officeTimes);
    return customer;

    std::cout << m_officeOrder->remove();




    }

void ServiceCenter::moveCustomer(Customer* customer){
    switch(customer->m_currentOffice){
        case 'C':
            m_cashier->m_enteringQueue->add(customer);
            break;
        case 'R':
            m_registrar->m_enteringQueue->add(customer);
            break;
        case 'F':
            m_financial->m_enteringQueue->add(customer);
            break;
        default:
            break;
    }
    // customer->printInfo();


}

void ServiceCenter::makeOffices(int R_windowNum, int C_windowNum, int F_windowNum){
    m_registrar = new Office('R', R_windowNum); //each have arrays for number of windows open at each office
    m_cashier = new Office('C', C_windowNum);
    m_financial = new Office('F', F_windowNum);
}


void ServiceCenter::advanceTick(){
    int customerNum = m_tickInfo->m_customerQueue->size();
    //std::cout << customerNum << std::endl;
    for (int i = 0; i < customerNum; ++i){
        if (m_tickInfo->m_customerQueue->peek()->getArriveTime() == m_clockTick){
            moveCustomer(m_tickInfo->m_customerQueue->remove());
        } 
    }

    //all offices have the first 3 students 

    m_registrar->advanceTick();
    m_cashier->advanceTick();
    m_financial->advanceTick();

    std::cout << "past past past past past" << std::endl;

    checkToMoveCustomer(m_cashier);
    checkToMoveCustomer(m_registrar);
    checkToMoveCustomer(m_financial);

    ++m_clockTick;
}


void ServiceCenter::checkToMoveCustomer(Office* office){
    while (!office->m_leavingQueue->isEmpty()){
        moveCustomer(office->m_leavingQueue->remove());
    }
}