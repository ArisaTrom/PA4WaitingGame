#include "Office.h"
#include <iostream>

Office::Office(){
    m_officeType = ' ';
    m_openWindows = 0;
    m_longestIdleTime = 0;
    m_longestWaitTime = 0;
    m_officeQueue = new ListQueue<Customer*>();
    m_enteringQueue = new ListQueue<Customer*>();
    m_leavingQueue = new ListQueue<Customer*>(); // leaving queue checked to the service center
}

Office::Office(char officeType, int windows){
    m_officeType = officeType;
    m_openWindows = windows;
    m_longestIdleTime = 0;
    m_longestWaitTime = 0;
    m_officeQueue = new ListQueue<Customer*>(); //customers waiting
    m_enteringQueue = new ListQueue<Customer*>();
    m_leavingQueue = new ListQueue<Customer*>();
    m_windows = new Window*[m_openWindows];      // array of windows 
    for (int i = 0; i < m_openWindows; ++i){
        m_windows[i] = new Window(m_officeQueue, m_enteringQueue);
    }
}

// Window* Office::getWindowsArr(){
//     return m_windows;
// }


Office::~Office(){
    if (m_officeType == 'C'){
        std::cout << "Cashier's Office: " << std::endl;
    } else if (m_officeType == 'R'){
        std::cout << "Registrar's Office: " << std::endl;
    } else if (m_officeType == 'F'){
        std::cout << "Financial Aid Office: " << std::endl;
    }
    displayFinalInfo();

    delete[] m_windows;
}

void Office::advanceTick(){
    if (!m_officeQueue->isEmpty()){
        // add to the wait time of each customer by putting them in queue and then readding them 
        ListQueue<Customer*>* tempQ = new ListQueue<Customer*>();
        while (!m_officeQueue->isEmpty()){
            Customer* customer = m_officeQueue->remove();
            customer->addWaitTime();
            tempQ->add(customer);
        }
        while (!tempQ->isEmpty()){
            Customer* customer = tempQ->remove();
            m_officeQueue->add(customer);
        }
    }
    for (int i = 0; i < m_openWindows; ++i){
        if (m_windows[i]->m_isOpen){
            if (m_officeQueue->isEmpty()){
                if (!m_enteringQueue->isEmpty()){
                    std::cout << "here 1" << std::endl;
                    m_windows[i]->customer = m_enteringQueue->remove();
                    m_windows[i]->studentVisiting();
                } else {
                    std::cout << "here 2" << std::endl;
                    m_windows[i]->increaseIdleTime();
                }
            } else {
                std::cout << "here 3" << std::endl;
                m_windows[i]->customer = m_officeQueue->remove();       // figure out window customer collision with entering queue customer
                m_windows[i]->studentVisiting();
            }
        } else {
            m_windows[i]->customer->decreaseOfficeTime();
            std::cout << "here 4" << std::endl;

            if (m_windows[i]->customer->m_currentOfficeTime == 0){
                std::cout << "here 5" << std::endl;
                // try to get new customer for window
                std::cout << "Removing Customer" << std::endl;
                removeCustomer(m_windows[i]);
            }

        }
    }
}

void Office::removeCustomer(Window* window){
    //longest idle time and longest wait time updates
    if (m_longestIdleTime < window->m_idleTime){
        m_longestIdleTime = window->m_idleTime;
    }
    if (m_longestWaitTime < window->customer->getWaitTime()){
        m_longestWaitTime = window->customer->getWaitTime();
    }

    std::cout << "in remove customer" << std::endl;
    window->customer->changeCurrentOffice();
    // issue
    std::cout << "in remove customer" << std::endl;
    window->customer->printInfo();

    if (window->customer->m_officeOrder->isEmpty()){
        std::cout << "deleting customer" << std::endl;
        delete window->customer;
        
    } else {
        //std::cout << "adding to leaving queue" << std::endl;
        m_leavingQueue->add(window->customer);
    }

    window->studentLeaving();
    window->getNewCustomer();

}
// TO DO: make method calculateMeanWaitTime() maybe


bool Office::isWindowsEmpty(){
    for (int i = 0; i < m_openWindows; ++i){
        if (m_windows[i]->m_isOpen){
            return false;
        }
    }
    return true;
}

void Office::displayFinalInfo(){
    std::cout << "Mean student wait time: " << calculateMeanWaitTime() << " minute(s)" << std::endl;
    std::cout << "Mean window idle time: " << calculateMeanIdleTime() << " minute(s)" << std::endl;
    std::cout << "Longest student wait time: " << m_longestWaitTime << " minute(s)" << std::endl;
    std::cout << "Longest window idle time: " << m_longestIdleTime << " minute(s)" << std::endl;
}

double Office::calculateMeanIdleTime(){
    double totalIdleTime = 0;
    for (int i = 0; i < m_openWindows; ++i){
        // std::cout << "Window Idle Time: " << m_windows[i]->m_idleTime << std::endl;
        totalIdleTime += m_windows[i]->m_idleTime;
    }
    return totalIdleTime / m_openWindows;
}

double Office::calculateMeanWaitTime(){
    double totalWaitTime = 0;
    int totalCustomersSeen = 0;
    for (int i = 0; i < m_openWindows; ++i){
        totalWaitTime += m_windows[i]->m_totalWaitTime;
        totalCustomersSeen += m_windows[i]->m_customersSeen;
    }
    //std::cout << totalWaitTime << std::endl;
    return totalWaitTime / totalCustomersSeen;

}

int Office::getStudentsWaitingOverTen(){
    int totalStudentsWaitingOverTen = 0;
    for (int i = 0; i < m_openWindows; ++i){
        totalStudentsWaitingOverTen += m_windows[i]->m_studentsWaitingOverTen;
    }
    return totalStudentsWaitingOverTen;
}

int Office::getWindowsIdleOverFive(){
    int totalWindows = 0;
    for (int i = 0; i < m_openWindows; ++i){
        if (m_windows[i]->m_idleTime > 5){
            totalWindows++;
        }
    }
    return totalWindows;
}
