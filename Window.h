/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Header file for Window.cpp
Contains constructor, destructor, and method declarations for interacting with Window objects.
*/

#ifndef WINDOW_H
#define WINDOW_H
#include "Customer.h"
#include "ListQueue.h"

//Comments relevant to the contents in this header file are in the respective cpp file, Window.cpp.

class Customer;

class Window{
    public:
        Window();
        Window(ListQueue<Customer*>* &officeQ);
        ~Window();
        void studentVisiting();
        void studentLeaving();
        bool m_isOpen;
        void increaseIdleTime();
        void getNewCustomer();
        int m_idleTime;
        Customer* customer;
        int m_studentsWaitingOverTen;
        int m_totalWaitTime;
        int m_customersSeen;
        ListQueue<Customer*>* m_officeQueue;
};

#endif