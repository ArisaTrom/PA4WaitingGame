/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Header file for Customer.cpp
Contains constructor, destructor, and method declarations for interacting with Customer objects.
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Office.h"
#include "ServiceCenter.h"
#include "ListQueue.h"

//Comments relevant to the contents in this header file are in the respective cpp file, Customer.cpp.

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