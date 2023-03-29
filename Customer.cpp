#include "Customer.h"

Customer::Customer(){
    m_arriveTime = 0;
    m_office1 = ' ';
    m_office2 = ' ';
    m_office3 = ' ';
    m_currentOffice = m_office1;
}

Customer::Customer(int arriveTime){
    m_arriveTime = arriveTime;
    m_office1 = ' ';
    m_office2 = ' ';
    m_office3 = ' ';
}

Customer::~Customer(){

}

void Customer::setOffice1(char office, int time){
    m_office1 = office;
    m_office1Time = time;
    m_currentOffice = m_office1;
}

void Customer::setOffice2(char office, int time){
    m_office2 = office;
    m_office2Time = time;
}

void Customer::setOffice3(char office, int time){
    m_office3 = office;
    m_office3Time = time;
}