#include "TickInfo.h"

TickInfo::TickInfo(){
    m_overallQueue = new ListQueue<ListQueue<Customer*>*>();
    m_customerQueue = new ListQueue<Customer*>();
}


TickInfo::~TickInfo(){
    delete m_overallQueue;
    delete m_customerQueue;
}

void TickInfo::addToCustomerQ(Customer* c){
    m_customerQueue->add(c);
}

void TickInfo::addToOverallQ(ListQueue<Customer*>* customerQ){
    m_overallQueue->add(customerQ);
}


