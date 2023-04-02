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
        int m_openWindows;
        Window** m_windows;
    private:
        char m_officeType;

        

};

#endif