/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Header file for ServiceCenter.cpp
Contains constructor, destructor, and method declarations for interacting with ServiceCenter objects.
*/

#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H
#include <string>
#include "Office.h"
#include "TickInfo.h"
#include "Customer.h"
#include "Office.h"

//Comments relevant to the contents in this header file are in the respective cpp file, ServiceCenter.cpp.

class Office;
class TickInfo;

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
        void checkToMoveCustomer(Office* office);

    private:
        bool isGameOver();
        int getStudentsWaitingOverTen();
        int getWindowsIdleOverFive();
        void processFile(std::string);
        char getOfficeChar(std::string value);
        Customer* collectStudentInfo(std::string line, int arriveTime);
        TickInfo* m_tickInfo;
        Office* m_registrar;
        Office* m_cashier;
        Office* m_financial;
};

#endif