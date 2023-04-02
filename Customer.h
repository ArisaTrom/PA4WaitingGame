#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Office.h"
#include "ServiceCenter.h"


class Customer{
    public:
        Customer();
        Customer(int arriveTime);
        ~Customer();
        int getArriveTime();
        char* m_officeOrder;
        int* m_officeTimes;
    private:
        char m_currentOffice;
        int m_arriveTime;
        int m_waitTime;
}; 

#endif