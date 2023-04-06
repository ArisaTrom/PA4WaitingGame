/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Contains constructor, destructor, and method implementations for interacting with TickInfo objects.
*/

#include "TickInfo.h"

//TickInfo constructor.
TickInfo::TickInfo(){
    m_customerQueue = new ListQueue<Customer*>();
}

//TickInfo destructor.
TickInfo::~TickInfo(){
    delete m_customerQueue;
}

//addToCustomerQ method.
//Parameters: Customer* c.
void TickInfo::addToCustomerQ(Customer* c){
    m_customerQueue->add(c);
}