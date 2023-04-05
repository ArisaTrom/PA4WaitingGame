#include "Customer.h"
#include <iostream>

Customer::Customer(){
    m_arriveTime = 0;
    m_officeOrder = new ListQueue<char>();
    m_officeTimes = new ListQueue<int>();
    m_currentOffice = m_officeOrder->remove();
    m_currentOfficeTime = m_officeTimes->remove();
}

Customer::Customer(int arriveTime, ListQueue<char>* officeOrder, ListQueue<int>* officeTimes){
    m_arriveTime = arriveTime;
    m_officeOrder = officeOrder;
    m_officeTimes = officeTimes;
    m_currentOffice = m_officeOrder->peek();
    m_currentOfficeTime = m_officeTimes->peek();
}

Customer::~Customer(){

}

int Customer::getArriveTime(){
    return m_arriveTime;
}

void Customer::addWaitTime(){
    m_waitTime++;
}

void Customer::decreaseOfficeTime(){
    std::cout << "jalkjfdjknfioeranf" << std::endl;
    if (m_officeTimes == NULL){
        std::cout << "office office office" << std::endl;
        return;
    }
    std::cout << "jalkjfdjknfioeranf" << std::endl;

    m_currentOfficeTime--;
    std::cout << "in decrease method" << std::endl;
    printInfo();
}

int Customer::getWaitTime(){
    return m_waitTime;
}

void Customer::changeCurrentOffice(){
    m_officeOrder->remove();
    m_officeTimes->remove();

    if (m_officeOrder->isEmpty()){
        std::cout << "changing" << std::endl;
        return;
    }
    m_currentOffice = m_officeOrder->peek();
    m_currentOfficeTime = m_officeTimes->peek();
    std::cout << "changing" << std::endl;

}

void Customer::printInfo(){
    std::cout << "student current Office: " << m_currentOffice << std::endl;
    std::cout << "student office Time: " << m_currentOfficeTime << std::endl;
    std::cout << "student office order queue: " << m_officeOrder->size() << std::endl;
}