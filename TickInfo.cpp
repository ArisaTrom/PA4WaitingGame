#include "TickInfo.h"

TickInfo::TickInfo(){
    m_customerQueue = new ListQueue<Customer*>();
}


TickInfo::~TickInfo(){
    delete m_customerQueue;
}

void TickInfo::addToCustomerQ(Customer* c){
    m_customerQueue->add(c);
}



