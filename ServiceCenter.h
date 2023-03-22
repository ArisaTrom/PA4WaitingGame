#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H
#include "Office.h"

class ServiceCenter{
    public:
        ServiceCenter();
        ServiceCenter(int rWindow, int cQindow, int fWindow);
        ~ServiceCenter();

    private:
        Office* m_registrar;
        Office* m_cashier;
        Office* m_financial;

        

};


#endif