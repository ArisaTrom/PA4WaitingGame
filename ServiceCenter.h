#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H
#include "Office.h"
#include "Customer.h"

class ServiceCenter{
    public:
        ServiceCenter();
        ServiceCenter(int rWindow, int cQindow, int fWindow);
        ~ServiceCenter();
        int clock; //global variable for clock ticks
        void serviceCenterSimulation();

    private:
        Office* m_registrar;
        Office* m_cashier;
        Office* m_financial;
        Customer** groups;
        //Customer* currGroup; //Need to populate with the students per group
        int Clock(); //Keeps track of ticks

        

};


#endif