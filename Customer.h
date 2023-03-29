#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    public:
        //Customer(char office1, char office2, char office3);
        Customer();
        Customer(int arriveTime);
        ~Customer();
        void setOffice1(char office, int time);
        void setOffice2(char office, int time);
        void setOffice3(char office, int time);
    private:
        char m_currentOffice;
        char m_office1;
        char m_office2;
        char m_office3;
        int m_arriveTime;
        int m_office1Time;
        int m_office2Time;
        int m_office3Time;
}; 

#endif