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
    m_currentOffice = m_officeOrder->remove();
    m_currentOfficeTime = m_officeTimes->remove();
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
    m_currentOfficeTime--;
}

int Customer::getWaitTime(){
    return m_waitTime;
}

void Customer::changeCurrentOffice(){
    m_currentOffice = m_officeOrder->remove();
    m_currentOfficeTime = m_officeTimes->remove();
}

void Customer::printInfo(){
    std::cout << "student current Office: " << m_currentOffice << std::endl;
    std::cout << "student office Time: " << m_currentOfficeTime << std::endl;
}