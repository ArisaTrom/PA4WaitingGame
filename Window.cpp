#include "Window.h"

Window::Window(){
    m_customersSeen = 0;
    m_totalWaitTime = 0;
    m_isOpen = true;
    m_studentsWaitingOverTen = 0;
    customer = nullptr;
}

Window::Window(ListQueue<Customer*>* &officeQ){
    m_customersSeen = 0;
    m_totalWaitTime = 0;
    m_officeQueue = officeQ;
    m_isOpen = true;
    m_studentsWaitingOverTen = 0;
    customer = nullptr;
}

Window::~Window(){

}


void Window::studentVisiting(){
    m_isOpen = false;
}

void Window::studentLeaving(){
    m_isOpen = true;
}

void Window::increaseIdleTime(){
    ++m_idleTime;
}

void Window::getNewCustomer(){
    ++m_customersSeen;
    m_totalWaitTime += customer->getWaitTime();
    if (customer->getWaitTime() > 10){
        ++m_studentsWaitingOverTen;
    }

    customer->changeCurrentOffice();

    if (m_officeQueue->isEmpty()){
        customer = nullptr;
    } else{
        customer = m_officeQueue->remove();
    }
}