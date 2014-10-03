#include "Heap.h"

Heap::Heap()
{
    arrayPointer = NULL;
    //ctor
}

Heap::~Heap()
{
    delete arrayPointer;
    arrayPointer = NULL;
    //dtor
}

void Heap::Insert(int data)
{
    if (arrayPointer == NULL)
    {
        arrayPointer = new int [2];
        arraySize = 2;
        arrayPointer[1] = data;
    }
    else
    {
        //Rescale after intial entry
        if (arraySize == 2)
        {
            rescale();
        }

        int i;
        for (i = 0; i < arraySize; i++)
        {
            //If we find a empty position
            if (arrayPointer[i] == 999999)
            {
                //Insert
                arrayPointer[i] = data;
                compareAndSwitch(i);

                if (i == (arraySize-1))
                {
                    rescale();
                }
                break;
            }
        }

    }
}

void Heap::rescale()
{
    int * temporaryPointer;
    temporaryPointer = new int [arraySize*2];
    for (int i = 0; i < arraySize*2; i++)
    {
        //Default Value
        temporaryPointer[i] = 999999;
    }
    for (int i = 0; i < arraySize; i++)
    {
        temporaryPointer[i] = arrayPointer[i];
    }
    arraySize = arraySize * 2;
    delete arrayPointer;
    arrayPointer = temporaryPointer;

    return;
}

void Heap::compareAndSwitch(int currentPosition)
{
    //If this is in an odd position
    if (currentPosition % 2 == 1)
    {
        if (arrayPointer[(currentPosition-1)/2] >= arrayPointer[currentPosition])
        {
            int temp = arrayPointer[(currentPosition-1)/2];
            arrayPointer[(currentPosition-1)/2] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue on until we reach the head node position
            if (((currentPosition-1)/2) != 1)
            {
                compareAndSwitch(((currentPosition-1)/2));
            }
        }
    }
    else if (currentPosition % 2 == 0)
    {
        if (arrayPointer[currentPosition/2] >= arrayPointer[currentPosition])
        {
            int temp = arrayPointer[currentPosition/2];
            arrayPointer[currentPosition/2] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue on until we reach the head node position
            if (currentPosition/2 != 1)
            {
                compareAndSwitch(currentPosition/2);
            }
        }
    }
    return;
}

int Heap::Delete()
{
    //If array is big enough
    int returnedNumber = arrayPointer[1];
    //If array is bigger than the intial node
    if (arraySize > 2)
    {
        int maximumNumber = 999999;
        //Find the last position in the list
        for (int i = 0; i < arraySize; i++)
        {
            if ((arrayPointer[i] == 999999) || (i+1 == arraySize))
            {
                //Save number and position
                maximumNumber = arrayPointer[i-1];
            }
        }

        arrayPointer[1] = maximumNumber;
        //Check it's children
        childComparison(1);
        return returnedNumber;
    }
    else
    {
        return returnedNumber;
    }
}

void Heap::childComparison(int currentPosition)
{
    //If this condition is satisfied, you have your heap updated completely
    if ((currentPosition * 2 + 1) < arraySize)
    {
        if ((arrayPointer[currentPosition*2] >= arrayPointer[currentPosition]) &&
            (arrayPointer[currentPosition*2 + 1] >= arrayPointer[currentPosition]))
            {
                //Accepted and returned
                return;
            }

        //If the left position is less than than the right but still less than the current position
        if (arrayPointer[currentPosition*2 + 1] > arrayPointer[currentPosition*2])
        {
            //Perform a swap
            int temp = arrayPointer[currentPosition*2];
            arrayPointer[currentPosition*2] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue checking
            childComparison(currentPosition*2);
            return;
        }
        else
        {
            int temp = arrayPointer[currentPosition*2 +1];
            arrayPointer[currentPosition*2 + 1] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue checking
            childComparison(currentPosition*2 +1);
            return;
        }
    }
}

void Heap::printHeap()
{
    for (int i = 1; i < arraySize; i++)
    {
        if (arrayPointer[i] != 999999)
        {
            std::cout << arrayPointer[i] << " ";
        }
    }
    std::cout << std::endl;
    return;
}


//Priority Queue Functions

PriorityQueue::PriorityQueue()
{
    arrayPointer = NULL;
}

PriorityQueue::~PriorityQueue()
{
    delete arrayPointer;
    arrayPointer = NULL;
}

void PriorityQueue::Insert(int data)
{
    if (arrayPointer == NULL)
    {
        arrayPointer = new int [2];
        arraySize = 2;
        arrayPointer[1] = data;
    }
    else
    {
        //Rescale after intial entry
        if (arraySize == 2)
        {
            rescale();
        }

        int i;
        for (i = 0; i < arraySize; i++)
        {
            //If we find a empty position
            if (arrayPointer[i] == -999999)
            {
                //Insert
                arrayPointer[i] = data;
                compareAndSwitch(i);

                if (i == (arraySize-1))
                {
                    rescale();
                }
                break;
            }
        }

    }
}

int PriorityQueue::Delete()
{
    //If array is big enough
    int returnedNumber = arrayPointer[1];
    //If array is bigger than the intial node
    if (arraySize > 2)
    {
        int minimumNumber = -999999;
        //Find the last position in the list
        for (int i = 0; i < arraySize; i++)
        {
            if ((arrayPointer[i] == -999999) || (i+1 == arraySize))
            {
                //Save number and position
                minimumNumber = arrayPointer[i-1];
            }
        }

        arrayPointer[1] = minimumNumber;
        //Check it's children
        childComparison(1);
        return returnedNumber;
    }
    else
    {
        return returnedNumber;
    }
}

void PriorityQueue::printQueue()
{
    for (int i = 1; i < arraySize; i++)
    {
        if (arrayPointer[i] != -999999)
        {
            std::cout << arrayPointer[i] << " ";
        }
    }
    std::cout << std::endl;
    return;
}

void PriorityQueue::rescale()
{
    int * temporaryPointer;
    temporaryPointer = new int [arraySize*2];
    for (int i = 0; i < arraySize*2; i++)
    {
        //Default Value
        temporaryPointer[i] = -999999;
    }
    for (int i = 0; i < arraySize; i++)
    {
        temporaryPointer[i] = arrayPointer[i];
    }
    arraySize = arraySize * 2;
    delete arrayPointer;
    arrayPointer = temporaryPointer;

    return;
}

void PriorityQueue::compareAndSwitch(int currentPosition)
{
    if (currentPosition % 2 == 1)
    {
        if (arrayPointer[(currentPosition-1)/2] <= arrayPointer[currentPosition])
        {
            int temp = arrayPointer[(currentPosition-1)/2];
            arrayPointer[(currentPosition-1)/2] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue on until we reach the head node position
            if (((currentPosition-1)/2) != 1)
            {
                compareAndSwitch(((currentPosition-1)/2));
            }
        }
    }
    else if (currentPosition % 2 == 0)
    {
        if (arrayPointer[currentPosition/2] <= arrayPointer[currentPosition])
        {
            int temp = arrayPointer[currentPosition/2];
            arrayPointer[currentPosition/2] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue on until we reach the head node position
            if (currentPosition/2 != 1)
            {
                compareAndSwitch(currentPosition/2);
            }
        }
    }
    return;
}

void PriorityQueue::childComparison(int currentPosition)
{
    //If this condition is satisfied, you have your heap updated completely
    if ((currentPosition * 2 + 1) < arraySize)
    {
        if ((arrayPointer[currentPosition*2] <= arrayPointer[currentPosition]) &&
            (arrayPointer[currentPosition*2 + 1] <= arrayPointer[currentPosition]))
            {
                //Accepted and returned
                return;
            }

        //If the left position is less than than the right but still less than the current position
        if (arrayPointer[currentPosition*2 + 1] < arrayPointer[currentPosition*2])
        {
            //Perform a swap
            int temp = arrayPointer[currentPosition*2];
            arrayPointer[currentPosition*2] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue checking
            childComparison(currentPosition*2);
            return;
        }
        else
        {
            int temp = arrayPointer[currentPosition*2 +1];
            arrayPointer[currentPosition*2 + 1] = arrayPointer[currentPosition];
            arrayPointer[currentPosition] = temp;
            //Continue checking
            childComparison(currentPosition*2 +1);
            return;
        }
    }
}
