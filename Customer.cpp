#include "Customer.h"

Customer::Customer(){
    m_arriveTime = 0;
    m_officeOrder = new char[3];
    m_officeTimes = new int[3];
    m_currentOffice = m_officeOrder[0];
}

Customer::Customer(int arriveTime){
    m_arriveTime = arriveTime;
    m_officeOrder = new char[3];
    m_officeTimes = new int[3];
    m_currentOffice = m_officeOrder[0];
}

Customer::~Customer(){

}

int Customer::getArriveTime(){
    return m_arriveTime;
}


