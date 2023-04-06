/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Header file for Office.cpp
Contains constructor, destructor, and method declarations for interacting with Office objects.
*/

#ifndef OFFICE_H
#define OFFICE_H
#include "Window.h"
#include <string>
#include "ListQueue.h"
#include "Customer.h"

//Comments relevant to the contents in this header file are in the respective cpp file, Office.cpp.

class Customer;
class Window;

class Office{
    public:
        Office();
        Office(char officeType, int windowNum);
        ~Office();
        ListQueue<Customer*>* m_officeQueue;
        ListQueue<Customer*>* m_enteringQueue;
        ListQueue<Customer*>* m_leavingQueue;
        int m_openWindows;
        Window** m_windows;
        void advanceTick();     
        void tryToFillWindow();
        void manageOfficeQueue();
        void removeCustomer(Window* window);
        int m_longestIdleTime;
        int m_longestWaitTime;
        bool isWindowsEmpty();
        void displayFinalInfo();
        void setLongestTimes(Window* window);
        double calculateMeanWaitTime();
        double calculateMeanIdleTime();
        int getStudentsWaitingOverTen();
        int getWindowsIdleOverFive();
        void fillWindow();

    private:
        char m_officeType;
        void handleOpenWindow(Window* window);
        void handleFullWindow(Window* window);
};

#endif