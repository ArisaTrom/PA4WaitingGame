#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <iostream>

ServiceCenter::ServiceCenter(){

}

ServiceCenter::ServiceCenter(std::string inFile){
    m_tickInfo = new TickInfo();
    processFile(inFile);
    
}

ServiceCenter::~ServiceCenter(){
    delete m_tickInfo;
    delete m_registrar;
    delete m_cashier;
    delete m_financial;
}

void ServiceCenter::serviceCenterSimulation(){
    // while (!m_tickInfo->m_overallQueue->isEmpty()){     // will be true while the overall queue is not empty
    //     ListQueue<Customer*>* customerQueue = m_tickInfo->m_overallQueue->remove();     // gets first in line customer queue 
    //     Customer* customer = customerQueue->remove();
    //     // for student Num we have to move customer bruhbruh bruh bruh bruh
    //     moveCustomer(customer);
    // }
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
                //need array for the tick times for each group, start collecting here.
                //start tick counter here, ServiceCenter -> clock =
                
                break;
            case 5:
                studentNum = stoi(line);
                break;
            case 6: 
                std::cout << R_windowNum << " is R window \n" << C_windowNum << " is C window \n" << F_windowNum << " is F window \n";
                std::cout << arriveTime << " is arrive time \n" << studentNum << " is studetn num " << std::endl;
                for (int i = 0; i < studentNum; ++i){
                    Customer* customer = collectStudentInfo(line, arriveTime);
                    m_tickInfo->addToCustomerQ(customer);

                    if (i != studentNum - 1){
                        getline(reader, line);   // gets line for next student
                        ++lineCount;
                        // std::cout << lineCount << " is current Line Count" << std::endl;
                    }
                }
                //lineCount;
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

        //after first chunk of info is collected(end of the last student, with the letters), if (line does not end in letters, increase group count)
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
    Customer* customer = new Customer();
    std::stringstream ss(line);
    std::string value;
    int valueCount = 1;
    while (ss >> value){
        switch(valueCount){
            case 1:
                customer->m_officeTimes[0] = stoi(value);
                break;
            case 2:
                customer->m_officeTimes[1] = stoi(value);
                break;
            case 3:
                customer->m_officeTimes[2] = stoi(value);
                break;
            case 4:
                customer->m_officeOrder[0] = getOfficeChar(value);
                break;
            case 5:
                customer->m_officeOrder[1] = getOfficeChar(value);
                break;
            case 6:
                customer->m_officeOrder[2] = getOfficeChar(value);
                break;
            default:
                break;
        }
        ++valueCount;
    }
    return customer;

    /*we can either to do clock variable here or in the service center*/
}

// scenario, student 1 and 2 is added to customer queue.
// to move customer into first office,  
// we remove them from the customer queue and 
// move them into the office queue
// too many to think about maybe start thinknig what happens when student arrives in a office 

void ServiceCenter::moveCustomer(){
    // remove them from customer queue using list queue remove method 
    // customer who comes first in the queue
    // if (customer->m_officeOrder[0] == 'R'){
    //     m_registrar->m_officeQueue->add(customer);
    // } else if ()



}

void ServiceCenter::makeOffices(int R_windowNum, int C_windowNum, int F_windowNum){
    m_registrar = new Office('R', R_windowNum);
    m_cashier = new Office('C', C_windowNum);
    m_financial = new Office('F', F_windowNum);
}