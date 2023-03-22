#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(){
    m_registrar = new Office();
    m_cashier = new Office();
    m_financial = new Office();
}

ServiceCenter::ServiceCenter(int rWindow, int cWindow, int fWindow){
    m_registrar = new Office("Registrar", rWindow);
    m_cashier = new Office("Cashier", cWindow);
    m_financial = new Office("Financial", fWindow);
}

ServiceCenter::~ServiceCenter(){
    delete m_registrar;
    delete m_cashier;
    delete m_financial;
}

// TO DO: make methods that do stuff tbd