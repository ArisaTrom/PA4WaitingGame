#include "Customer.h"

Customer::Customer(){
    m_arriveTime = 0;
    m_officeOrder = new char[3];
    m_officeTimes = new int[3];
    m_currentOffice = m_officeOrder[0];
}

// Customer::Customer(int arriveTime){
//     m_arriveTime = arriveTime;
//     m_office1 = ' ';
//     m_office2 = ' ';
//     m_office3 = ' ';
// }

Customer::~Customer(){

}

void Customer::populateOfficeOrder(/*idk where we would get the input from, main?*/){
    
}

// void Customer::setOffice2(char office, int time){
//     m_office2 = office;
//     m_office2Time = time;
// }

// void Customer::setOffice3(char office, int time){
//     m_office3 = office;
//     m_office3Time = time;
// }