#include "customer.h"

customer::customer()
{
    //Constructor
    currentWaitTime = 0;
    itemCount = 1;
    serviceTime = 0;
}

customer::~customer()
{

}

void customer::test()
{
    incrementWaitTime();
    incrementWaitTime();
    incrementWaitTime();

    std::cout << currentWaitTime;

    return;
}


void customer::incrementWaitTime()
{
    currentWaitTime = currentWaitTime++;
}

void customer::incrementServiceTime()
{
    serviceTime = serviceTime++;
}

void customer::resetServiceTime()
{
    serviceTime = 0;
}

void customer::setItemCount(int newCount)
{
    itemCount = newCount;
}

int customer::returnWaitTime()
{
    return currentWaitTime;
}

int customer::returnItemCount()
{
    return itemCount;
}

int customer::returnServiceTime()
{
    return serviceTime;
}
