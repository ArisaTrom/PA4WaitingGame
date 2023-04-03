#include "Window.h"

Window::Window(){
    m_isOpen = true;
    m_studentsWaitingOverTen = 0;
}

Window::Window(ListQueue<Customer*>* &officeQ){
    m_officeQueue = officeQ;
    m_isOpen = true;
    m_studentsWaitingOverTen = 0;
}

Window::~Window(){

}

// TO DO: mehtod that returns the wait time

void Window::studentVisiting(int windowTime){
    if (!m_isOpen){     // if window is closed
        // do something
    }
    m_isOpen = false;

}

void Window::studentLeaving(){
    m_isOpen = true;
}

void Window::increaseIdleTime(){
    ++m_idleTime;
}

void Window::getNewCustomer(){
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