#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Office.h"
#include "ServiceCenter.h"
#include "ListQueue.h"


class Customer{
    public:
        Customer();
        Customer(int arriveTime, ListQueue<char>* officeOrder, ListQueue<int>* officeTimes);
        ~Customer();
        int getArriveTime();
        ListQueue<char>* m_officeOrder;
        ListQueue<int>* m_officeTimes;   // needs to be decreased for each advance tick
        void addWaitTime();
        void decreaseOfficeTime();
        char m_currentOffice;
        int m_currentOfficeTime;
        int getWaitTime();
        void changeCurrentOffice();
        void printInfo();
    private:
        int m_arriveTime;
        int m_waitTime;  
}; 

#endif