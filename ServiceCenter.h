#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H
#include <string>
#include "Office.h"
#include "TickInfo.h"
#include "Customer.h"

class ServiceCenter{
    public:
        ServiceCenter();
        ServiceCenter(std::string inFile);
        ~ServiceCenter();
        int m_clockTick; //global variable for clock ticks
        void serviceCenterSimulation();
        void moveCustomer(Customer* customer);
        void enterOffice(Customer* customer, char officeChar, int time);
        void makeOffices(int R_windowNum, int C_windowNum, int F_windowNum);
        void advanceTick();

    private:
        void processFile(std::string);
        char getOfficeChar(std::string value);
        Customer* collectStudentInfo(std::string line, int arriveTime);
        TickInfo* m_tickInfo;
        Office* m_registrar;
        Office* m_cashier;
        Office* m_financial;
        Customer** groups;
        //Customer* currGroup; //Need to populate with the students per group
        //int Clock(); //Keeps track of ticks

        

};


#endif