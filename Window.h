#ifndef WINDOW_H
#define WINDOW_H
#include "Customer.h"
#include "ListQueue.h"

class Customer;

class Window{
    public:
        Window();
        Window(ListQueue<Customer*>* &officeQ, ListQueue<Customer*>* &enteringQ);
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
        ListQueue<Customer*>* m_enteringQueue;
};

#endif