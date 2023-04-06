/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Header file for TickInfo.cpp
Contains constructor, destructor, and method declarations for interacting with TickInfo objects.
*/

#ifndef TICK_INFO_H
#define TICK_INFO_H
#include "ListQueue.h"
#include "Customer.h"

//Comments relevant to the contents in this header file are in the respective cpp file, TickInfo.cpp.

class Customer;

class TickInfo{
    public:
        TickInfo();
        ~TickInfo();
        void tickForward();
        void addToCustomerQ(Customer* customer);
        ListQueue<Customer*>* m_customerQueue;

};

#endif