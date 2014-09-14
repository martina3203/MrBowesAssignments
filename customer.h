#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class customer
{
    public:
        customer();
        virtual ~customer();
        void incrementWaitTime();
        void setItemCount(int);
        void incrementServiceTime();
        void resetServiceTime();
        int returnWaitTime();
        int returnItemCount();
        int returnServiceTime();
        void test();
    protected:
    private:
        int currentWaitTime;
        int itemCount;
        int serviceTime;
};

#endif // CUSTOMER_H
