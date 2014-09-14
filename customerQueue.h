#ifndef CUSTOMERQUEUE_H
#define CUSTOMERQUEUE_H

#include "singleLink.h"
#include <stdlib.h>
#include <time.h>


class customerQueue
{
    public:
        customerQueue();
        void addToQueue(customer newCustomer);
        customer removeFromQueue();
        void updateQueueTime();
        int returnSize();
        std::vector<customer> returnVector();
        virtual ~customerQueue();
    protected:
    private:

};




class queueSimulation
{
public:
    queueSimulation();
    ~queueSimulation();
    void executeOneCashier(bool normalServiceTime = true);
    void executeMultiEverything();
    void executeMultiRegister();
    //1 is for One Cashier information, 2 is for MultiEverything, 3 is for MultiRegister
    void printChart(int queueCode);
    void updateStats(int queueCode,customerQueue targetList);
private:
    int totalTimeOneCashier;
    int totalTimeMultiEverything;
    int totalTimeMultiRegister;
    int totalCustomersServedOneCashier;
    int totalCustomersServedMultiEverything;
    int totalCustomersServedMultiRegister;
    float AverageWaitOneCashier;
    float AverageWaitMultiEverything;
    float AverageWaitMultiRegister;
    int maxWaitTimeOneCashier;
    int maxWaitTimeMultiEverything;
    int maxWaitTimeMultiRegister;
};

#endif // CUSTOMERQUEUE_H
