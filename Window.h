#ifndef WINDOW_H
#define WINDOW_H
#include "Customer.h"

class Window{
    public:
        Window();
        Window(ListQueue<Customer*>* &officeQ);
        ~Window();
        void studentVisiting(int windowTime);
        void studentLeaving();
        bool m_isOpen;
        void increaseIdleTime();
        void getNewCustomer();
        int m_idleTime;
        Customer* customer;
        int m_studentsWaitingOverTen;
        ListQueue<Customer*>* m_officeQueue;
};

#endif