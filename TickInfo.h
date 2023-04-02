#ifndef TICK_INFO_H
#define TICK_INFO_H
#include "ListQueue.h"
#include "Customer.h"

class TickInfo{
    public:
        TickInfo();
        ~TickInfo();
        void tickForward();
        void addToCustomerQ(Customer* customer);
        void addToOverallQ(ListQueue<Customer*>* customerQ);
        ListQueue<ListQueue<Customer*>*>* m_overallQueue;
        ListQueue<Customer*>* m_customerQueue;

};

#endif