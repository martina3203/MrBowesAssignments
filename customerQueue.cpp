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
}

customer customerQueue::removeFromQueue()
{


}

void customerQueue::updateQueueTime()
{


}

int customerQueue::returnSize()
{

}

std::vector<customer> customerQueue::returnVector()
{

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

    //Seeds random number generator
    srand(time(NULL));
}

queueSimulation::~queueSimulation()
{

}

void queueSimulation::executeOneCashier(bool normalServiceTime)
{
    //Create Cashier and Queue
    customer Cashier;
    customerQueue theLine;
    customerQueue exitLine;

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
            customer newCustomer;
            exitLine.addToQueue(newCustomer);
        }

        //Update time
        totalTimeOneCashier++;
        //theLine.updateQueueTime();


        //Prints information if the times are just right
        if ((totalTimeOneCashier == 30) || (totalTimeOneCashier == 60) || (totalTimeOneCashier == 120) || (totalTimeOneCashier == 480))
        {
            //Prints chart
            updateStats(1,exitLine);
            printChart(1);
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


void queueSimulation::updateStats(int queueCode,customerQueue targetList)
{
    float maxTime = 0;
    int averageWait = 0;
    std::vector<customer> savedVector = targetList.returnVector();
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

