#include "Office.h"

Office::Office(){
    m_officeType = ' ';
    m_openWindows = 0;
    m_longestIdleTime = 0;
    m_longestWaitTime = 0;
    m_officeQueue = new ListQueue<Customer*>();
    m_leavingQueue = new ListQueue<Customer*>(); // leaving queue checked to the service center
}

Office::Office(char officeType, int windows){
    m_officeType = officeType;
    m_openWindows = windows;
    m_longestIdleTime = 0;
    m_longestWaitTime = 0;
    m_officeQueue = new ListQueue<Customer*>(); //customers waiting
    m_leavingQueue = new ListQueue<Customer*>();
    m_windows = new Window*[m_openWindows];      // array of windows 
    for (int i = 0; i < m_openWindows; ++i){
        m_windows[i] = new Window(m_officeQueue);
    }
}

// Window* Office::getWindowsArr(){
//     return m_windows;
// }


Office::~Office(){
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
                m_windows[i]->increaseIdleTime();
            } else {
                m_windows[i]->customer = m_officeQueue->remove();
            }
        } else {
            m_windows[i]->customer->decreaseOfficeTime();
            if (m_windows[i]->customer->m_currentOfficeTime == 0){
                // try to get new customer for window
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

    if (window->customer->m_officeOrder->isEmpty()){
        delete window->customer;
    } else {
        m_leavingQueue->add(window->customer);
    }

    window->getNewCustomer();
}
// TO DO: make method calculateMeanWaitTime() maybe
