#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    public:
        Customer(char office1, char office2, char office3);
        ~Customer();
    private:
        int rTime;
        int cTime;
        int fTime;
}; 

#endif