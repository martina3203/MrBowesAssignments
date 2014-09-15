#include "customerQueue.h"


customerQueue::customerQueue()
{

}

customerQueue::~customerQueue()
{
    //dtor
}

void customerQueue::addToQueue(customer newCustomer)
{
    return theList.Add(newCustomer);
}

customer customerQueue::removeFromQueue()
{
    return theList.Remove();
}

void customerQueue::updateQueueTime()
{
    theList.updateTime();
    return;
}

int customerQueue::returnSize()
{
    theList.returnSize();
}

std::vector<customer> customerQueue::returnVector()
{
    return theList.returnVector();
}




//QUEUE SIMULATION STUFF


queueSimulation::queueSimulation()
{
    totalTimeOneCashier = 0;
    totalTimeMultiEverything = 0;
    totalTimeMultiRegister = 0;
    totalCustomersServedOneCashier = 0;
    totalCustomersServedMultiEverything = 0;
    totalCustomersServedMultiRegister = 0;
    AverageWaitOneCashier = 0;
    AverageWaitMultiEverything = 0;
    AverageWaitMultiRegister = 0;
    maxWaitTimeOneCashier = 0;
    maxWaitTimeMultiEverything = 0;
    maxWaitTimeMultiRegister = 0;

    //Maximum values
    mostCustomersCompleted = 0;
    CMCode = 0;
    bestAverageWait = 0;
    BACode = 0;
    worstWaitTime = 0;
    WWCode = 0;

    //Seeds random number generator
    srand(time(NULL));
}

queueSimulation::~queueSimulation()
{

}

void queueSimulation::executeAll(bool normalServiceTime)
{
    for (unsigned int i = 0; i < 100; i++)
    {
        executeOneCashier(normalServiceTime);
        executeMultiEverything(normalServiceTime);
        executeMultiRegister(normalServiceTime);

        resetStats();
    }

    return;
}


void queueSimulation::executeOneCashier(bool normalServiceTime)
{
    //Create Cashier and Queue
    customer Cashier;
    customerQueue theLine;
    std::vector<customer> fuckThisVector;

    while (totalTimeOneCashier < 480)
    {
        //Assign a number of new customers that will be added to the Queue every minute
        unsigned int newCustomersPerMinute = rand() % 3;
        for (unsigned int i = 0; i < newCustomersPerMinute; i++)
        {
            customer newCustomer;
            theLine.addToQueue(newCustomer);
        }

        //If this is normal service time
        if (normalServiceTime == true)
        {
            if (Cashier.returnServiceTime() == 1)
            {
                fuckThisVector.push_back(Cashier);
                Cashier.resetServiceTime();
            }
            if (theLine.returnSize() != 0)
            {
                Cashier = theLine.removeFromQueue();
                Cashier.incrementServiceTime();
            }
        }

        //Update time
        totalTimeOneCashier++;
        theLine.updateQueueTime();


        //Prints information if the times are just right
        if ((totalTimeOneCashier == 30) || (totalTimeOneCashier == 60) || (totalTimeOneCashier == 120) || (totalTimeOneCashier == 480))
        {
            //Prints chart
            updateStats(1,fuckThisVector);
            printChart(1);
        }
    }
    return;
}

void queueSimulation::executeMultiEverything(bool normalServiceTime)
{
    //Create Cashier and Queue
    customer CashierOne;
    customer CashierTwo;
    customerQueue firstLine;
    customerQueue secondLine;
    std::vector<customer> fuckThisVector;

    while (totalTimeMultiEverything < 480)
    {
        //Assign a number of new customers that will be added to the Queue every minute
        unsigned int newCustomersPerMinute = rand() % 3;
        for (unsigned int i = 0; i < newCustomersPerMinute; i++)
        {
            customer newCustomer;
            if (firstLine.returnSize() < secondLine.returnSize())
            {
                firstLine.addToQueue(newCustomer);
            }
            else
            {
                secondLine.addToQueue(newCustomer);
            }
        }

        //If this is normal service time
        if (normalServiceTime == true)
        {
            //First Line handling
            if (CashierOne.returnServiceTime() == 1)
            {
                fuckThisVector.push_back(CashierOne);
                CashierOne.resetServiceTime();
            }
            if (firstLine.returnSize() != 0)
            {
                CashierOne = firstLine.removeFromQueue();
                CashierOne.incrementServiceTime();
            }

            //Second Line handling
            if (CashierTwo.returnServiceTime() == 1)
            {
                fuckThisVector.push_back(CashierTwo);
                CashierTwo.resetServiceTime();
            }
            if (secondLine.returnSize() != 0)
            {
                CashierTwo = secondLine.removeFromQueue();
                CashierTwo.incrementServiceTime();
            }
        }

        //Update time
        totalTimeMultiEverything++;
        firstLine.updateQueueTime();
        secondLine.updateQueueTime();

        //Prints information if the times are just right
        if ((totalTimeMultiEverything == 30) || (totalTimeMultiEverything == 60) || (totalTimeMultiEverything == 120) || (totalTimeMultiEverything == 480))
        {
            //Prints chart
            updateStats(2,fuckThisVector);
            printChart(2);
        }
    }
    return;
}

void queueSimulation::executeMultiRegister(bool normalServiceTime)
{
    //Create Cashier and Queue
    customer CashierOne;
    customer CashierTwo;
    customerQueue theLine;
    std::vector<customer> fuckThisVector;

    while (totalTimeMultiRegister < 480)
    {
        //Assign a number of new customers that will be added to the Queue every minute
        unsigned int newCustomersPerMinute = rand() % 3;
        for (unsigned int i = 0; i < newCustomersPerMinute; i++)
        {
            customer newCustomer;
            theLine.addToQueue(newCustomer);
        }

        //If this is normal service time
        if (normalServiceTime == true)
        {
            if (CashierOne.returnServiceTime() == 1)
            {
                fuckThisVector.push_back(CashierOne);
                CashierOne.resetServiceTime();
            }
            if (CashierTwo.returnServiceTime() == 1)
            {
                fuckThisVector.push_back(CashierTwo);
                CashierTwo.resetServiceTime();
            }
            if (CashierOne.returnServiceTime() < 1)
            {
                if (theLine.returnSize() != 0)
                {
                    CashierOne = theLine.removeFromQueue();
                    CashierOne.incrementServiceTime();
                }
            }
            if (CashierTwo.returnServiceTime() < 1)
            {
                if (theLine.returnSize() != 0)
                {
                    CashierTwo = theLine.removeFromQueue();
                    CashierTwo.incrementServiceTime();
                }
            }
        }

        //Update time
        totalTimeMultiRegister++;
        theLine.updateQueueTime();

        //Prints information if the times are just right
        if ((totalTimeMultiRegister == 30) || (totalTimeMultiRegister == 60) || (totalTimeMultiRegister == 120) || (totalTimeMultiRegister == 480))
        {
            //Prints chart
            updateStats(3,fuckThisVector);
            printChart(3);
        }
    }
    return;
}


void queueSimulation::printChart(int queueCode)
{
    std::string titleString;
    int totalTime;
    int averageWaitTime;
    float maxWaitTime;
    int customersServed;
    //One Cashier
    if (queueCode == 1)
    {
        titleString = "One Cashier, One Line Queue";
        totalTime = totalTimeOneCashier;
        averageWaitTime = AverageWaitOneCashier;
        maxWaitTime = maxWaitTimeOneCashier;
        customersServed = totalCustomersServedOneCashier;
    }
    //Multi Everything
    else if (queueCode == 2)
    {
        titleString = "Multiple Cashiers, Multiple Lines";
        totalTime = totalTimeMultiEverything;
        averageWaitTime = AverageWaitMultiEverything;
        maxWaitTime = maxWaitTimeMultiEverything;
        customersServed = totalCustomersServedMultiEverything;
    }
    //Multi Cashier
    else if (queueCode == 3)
    {
        titleString = "Multiple Cashiers, One Line";
        totalTime = totalTimeMultiRegister;
        averageWaitTime = AverageWaitMultiRegister;
        maxWaitTime = maxWaitTimeMultiRegister;
        customersServed = totalCustomersServedMultiRegister;
    }
    else
    {
        //Failure to select correct queue
        return;
    }


    std::cout << titleString << std::endl;
    std::cout << "Total Operating Time: \t" << totalTime << std::endl;
    std::cout << "Average Wait Time: \t" << averageWaitTime << std::endl;
    std::cout << "Maximum Wait Time: \t" << maxWaitTime << std::endl;
    std::cout << "Customers Served: \t" << customersServed << std::endl;

}


void queueSimulation::updateStats(int queueCode,std::vector<customer> savedVector)
{
    float maxTime = 0;
    int averageWait = 0;
    //Find max time and the average of the wait times

    for (unsigned int i = 0; i < savedVector.size(); i++)
    {
        //This adds up all the wait times
        averageWait = averageWait + savedVector.at(i).returnWaitTime();
        //This actually finds the longest wait time
        if (maxTime < savedVector.at(i).returnWaitTime())
        {
            maxTime = savedVector.at(i).returnWaitTime();
        }
    }

    if (savedVector.size() != 0)
    {
        averageWait = (averageWait/savedVector.size());
    }

    //Single Cashier
    if (queueCode == 1)
    {
        AverageWaitOneCashier = averageWait;
        maxWaitTimeOneCashier = maxTime;
        totalCustomersServedOneCashier = savedVector.size();
    }
    //Multi Everything
    else if (queueCode == 2)
    {
        AverageWaitMultiEverything = averageWait;
        maxWaitTimeMultiEverything = maxTime;
        totalCustomersServedMultiEverything = savedVector.size();
    }
    //Multi Cashier
    else if (queueCode == 3)
    {
        AverageWaitMultiRegister = averageWait;
        maxWaitTimeMultiRegister = maxTime;
        totalCustomersServedMultiRegister = savedVector.size();
    }

    return;
}

void queueSimulation::resetStats()
{
    if (mostCustomersCompleted < totalCustomersServedOneCashier)
    {
        CMCode = 1;
        mostCustomersCompleted = totalCustomersServedOneCashier;
    }
    if (mostCustomersCompleted < totalCustomersServedMultiEverything)
    {
        CMCode = 2;
        mostCustomersCompleted = totalCustomersServedMultiEverything;
    }
    if (mostCustomersCompleted < totalCustomersServedMultiRegister)
    {
        CMCode = 3;
        mostCustomersCompleted = totalCustomersServedMultiRegister;
    }

    if (bestAverageWait < AverageWaitOneCashier)
    {
        BACode = 1;
        bestAverageWait = AverageWaitOneCashier;
    }
    if (bestAverageWait < AverageWaitMultiEverything)
    {
        BACode = 2;
        bestAverageWait = AverageWaitMultiEverything;
    }
    if (bestAverageWait < AverageWaitMultiRegister)
    {
        BACode = 3;
        bestAverageWait = AverageWaitMultiEverything;
    }

    totalTimeOneCashier = 0;
    totalTimeMultiEverything = 0;
    totalTimeMultiRegister = 0;
    totalCustomersServedOneCashier = 0;
    totalCustomersServedMultiEverything = 0;
    totalCustomersServedMultiRegister = 0;
    AverageWaitOneCashier = 0;
    AverageWaitMultiEverything = 0;
    AverageWaitMultiRegister = 0;
    maxWaitTimeOneCashier = 0;
    maxWaitTimeMultiEverything = 0;
    maxWaitTimeMultiRegister = 0;
}

void queueSimulation::printFinalStats()
{

}
