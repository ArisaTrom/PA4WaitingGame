#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <iostream>

ServiceCenter::ServiceCenter(){
    m_clockTick = 0;
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
    while (!m_tickInfo->m_overallQueue->isEmpty()){     // will be true while the overall queue is not empty 
        ListQueue<Customer*>* customerQueue = m_tickInfo->m_overallQueue->remove();// gets first in line customer queue 
        Customer* customer = customerQueue->remove();       // not from tick info customer q might have to fix 
        // for student Num we have to move customer bruhbruh bruh bruh bruh
        moveCustomer(customer);
    }

    //USE GLOBAL TICK TIMER AND ADD 1 FOR EVERY FOR LOOP??
    //Simulate the service center based on ticks.
    for (int i=1; i<=10; i++){ //assume that there won't be more than 10 ticks.
        for (int j=0; j<m_registrar->m_openWindows; j++){
            //iterate through array of windows, evaluate if open or not
            if (m_registrar->m_windows[j]->m_isOpen == true){ //if registrar window is open
                //put student there
                for (int m=1; m<=; m++){
                    m_registrar->m_windows[j]->m_isOpen = false; //student is occupying the window
                    m_clockTick++;
                }
            }
        }
        for (int k=0; k<m_registrar->m_openWindows; k++){
            //iterate through array of windows, evaluate if open or not
            if (m_cashier->m_windows[k]->m_isOpen == true){ //if registrar window is open
                //put student there
            }
        }
        for (int l=0; l<m_registrar->m_openWindows; l++){
            //iterate through array of windows, evaluate if open or not
            if (m_financial->m_windows[l]->m_isOpen == true){ //if registrar window is open
                //put student there
            }
        }
    }
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
                    Customer* customer = collectStudentInfo(line, arriveTime);      // makes customer
                    m_tickInfo->addToCustomerQ(customer);                           // adds to queue for this tick 

                    if (i != studentNum - 1){
                        getline(reader, line);   // gets line for next student
                        ++lineCount;
                        // std::cout << lineCount << " is current Line Count" << std::endl;
                    }
                }
                m_tickInfo->addToOverallQ(m_tickInfo->m_customerQueue);
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

    /*we can either to do clock variable here or in the service center*/
}

// scenario, student 1 and 2 is added to customer queue.
// to move customer into first office,  
// we remove them from the customer queue and 
// move them into the office queue
// too many to think about maybe start thinknig what happens when student arrives in a office 

void ServiceCenter::moveCustomer(Customer* customer){
    // remove them from customer queue using list queue remove method 
    // customer who comes first in the queue
    // if (customer->m_officeOrder[0] == 'R'){
    //     m_registrar->m_officeQueue->add(customer);
    // } else if ()
    //enterOffice(customer, customer->m_officeOrder[0], customer->m_officeTimes[0]);



}

void ServiceCenter::makeOffices(int R_windowNum, int C_windowNum, int F_windowNum){
    m_registrar = new Office('R', R_windowNum); //each have arrays for number of windows open at each office
    m_cashier = new Office('C', C_windowNum);
    m_financial = new Office('F', F_windowNum);
}

void ServiceCenter::enterOffice(Customer* customer, char officeChar, int time){
    if (officeChar == 'R'){
        m_registrar->m_officeQueue->add(customer); // goes for time 5
    } else if (officeChar == 'C'){
        m_cashier->m_officeQueue->add(customer);
    } else if (officeChar == 'F'){
        m_financial->m_officeQueue->add(customer);
    }
}

// advance tick (){ // getting called in while loop while game is still 
//     calls advance tick for each Office

// }


//     R
// 1 S1 
// 2 S1
// 3 S1 S3
// 4 S1 S3
// 5 S1 S3
// 6    S3


void ServiceCenter::advanceTick(){
    
}


// CUstomer queue (S1 S2 S3)
// clocks at time 1
// add time 1 customers S1 S2
// for (){
//      Customer* customer = CustomerQueue->remove();
//        if (customer->m_arriveTime == clocktime){
//                             enterOffice(customer, customer->m_officeOrder[1], customer->m_OfficeTimes[1]);
//                     }
//
//}
// ;
// 