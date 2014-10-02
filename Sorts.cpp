#include "Sorts.h"


int main()
{
    int magicArray[10] = {67,8,14,2,36,2,42,19,30,15};
    //selectionSort(10,magicArray);
    //insertionSort(10,magicArray);
    //bubbleSort(10,magicArray);
    shellSort(10,magicArray);

    printArray(10,magicArray);
    return 1;
}


void selectionSort(int arraySize,int theArray[])
{
    unsigned int i;
    unsigned int h;
    int minimumItem;
    for (i = 0; i < arraySize-1; i++)
    {
        //Set the minimum position to be the first position
        minimumItem = i;
        for (h = i+1; h < arraySize; h++)
        {
            //If the value at the H position is less than the value of the previous set minimum position
            if (theArray[h] < theArray[minimumItem])
            {
                //Create a new position
                minimumItem = h;
            }
        }
        //Swap value
        SwapValues(minimumItem,i,theArray);
    }
    return;
}

void insertionSort(int arraySize,int theArray[])
{
    //Pull a Number out
    //Compare to previous numbers and fit it in accordingly
    //Cycle to next number
    unsigned int i;
    unsigned int j;
    unsigned int minimumValue;
    for (i = 0; i < arraySize; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (theArray[j] < theArray[j-1])
            {
                SwapValues(j,j-1,theArray);
            }
        }
    }

    return;
}

void bubbleSort(int arraySize,int theArray[])
{
    //While not sorted
    bool sorted = false;
    while (sorted != true)
    {
        //Reset flag
        sorted = true;
        for (unsigned int i = 0; i < arraySize-1; i++)
        {
            //If first value is greater than second, set flag and swap
            if (theArray[i] > theArray[i+1])
            {
                sorted = false;
                SwapValues(i,i+1,theArray);
            }
        }
    }
    return;
}

void shellSort(int arraySize,int theArray[])
{
    //This is a Shell Sort that utilizes 5, 3, 1
    //I printed the array mid way through the swap so you can see the changes.
    unsigned int i;
    //5 sort
    for (i = 0; i < arraySize; i++)
    {
        if (i+5 < arraySize)
        {
            if (theArray[i] > theArray[(i+5)])
            {
                SwapValues((i),((i+5)),theArray);
            }
        }
    }
    printArray(arraySize,theArray);
    std::cout << std::endl;
    //3 Sort

    for (i = 0; i < arraySize; i++)
    {
        if (i+3 < arraySize)
        {
            if (theArray[i] > theArray[(i+3)])
            {
                SwapValues((i),((i+3)),theArray);
            }
        }
    }
    printArray(arraySize,theArray);
    std::cout << std::endl;
    //1 Sort, which by definition, is just an insertion sort
    insertionSort(arraySize,theArray);

    return;
}


void printArray(int arraySize,int theArray[])
{
    //Prints every element of the array
    for (unsigned int i = 0; i < arraySize; i++)
    {
        std::cout << theArray[i] << " ";
    }
    return;
}

void SwapValues(int firstPosition,int secondPosition, int theArray[])
{
    //Swaps two positions in an array
    int savedValue = theArray[firstPosition];
    theArray[firstPosition] = theArray[secondPosition];
    theArray[secondPosition] = savedValue;
    return;
}
