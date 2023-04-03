#ifndef OFFICE_H
#define OFFICE_H
#include "Window.h"
#include <string>
#include "ListQueue.h"
#include "Customer.h"

class Office{
    public:
        Office();
        Office(char officeType, int windowNum);
        ~Office();
        ListQueue<Customer*>* m_officeQueue;
        ListQueue<Customer*>* m_leavingQueue;
        int m_openWindows;
        Window** m_windows;
        void advanceTick();     
        void removeCustomer(Window* window);
        int m_longestIdleTime;
        int m_longestWaitTime;

        //
    private:
        char m_officeType;

        

};

#endif