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
    private:
        int m_openWindows;
        char m_officeType;
        Window* m_windows;

        

};

#endif