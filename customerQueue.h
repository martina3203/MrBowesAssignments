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
        singleLink theList;

};




class queueSimulation
{
public:
    queueSimulation();
    ~queueSimulation();
    void executeAll(bool normalServiceTime = true);
    void executeOneCashier(bool normalServiceTime = true);
    void executeMultiEverything(bool normalServiceTime = true);
    void executeMultiRegister(bool normalServiceTime = true);
    //1 is for One Cashier information, 2 is for MultiEverything, 3 is for MultiRegister
    void printChart(int queueCode);
    void updateStats(int queueCode,std::vector<customer> savedVector);
    void resetStats();
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

    //Max Values
    int mostCustomersCompleted;
    int CMCode = 0;
    int bestAverageWait;
    int BACode = 0;
    int worstWaitTime;
    int WWCode = 0;
};

#endif // CUSTOMERQUEUE_H
