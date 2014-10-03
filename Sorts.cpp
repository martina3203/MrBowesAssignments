#include "Sorts.h"
#include "Heap.h"

int main()
{
    int magicArray[10] = {67,8,14,2,36,2,42,19,30,15};

    //used a vector for some sorts because I am lazy
    std::vector<int> magicVector; magicVector.push_back(10); magicVector.push_back(4); magicVector.push_back(19);
    magicVector.push_back(4); magicVector.push_back(47); magicVector.push_back(-9);
    //selectionSort(10,magicArray);
    //insertionSort(10,magicArray);
    //bubbleSort(10,magicArray);
    //shellSort(10,magicArray);
    //quickSort(0,9,magicArray);
    //mergeSort(magicVector);
    heapSort(10,magicArray);

    Heap newHeap; newHeap.Insert(5); newHeap.Insert(6); newHeap.Insert(3); newHeap.Insert(9);
    newHeap.Insert(5); newHeap.Insert(11); newHeap.Insert(1);
    newHeap.printHeap();
    newHeap.Delete();
    newHeap.printHeap();

    /*
    PriorityQueue newQueue; newQueue.Insert(10); newQueue.Insert(3); newQueue.Insert(15);
    newQueue.printQueue();
    newQueue.Delete();  newQueue.Delete(); newQueue.Delete();
    newQueue.printQueue();
    */

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

void quickSort(int firstPosition,int lastPosition, int theArray[])
{
    //Terminates when the numbers are equal
    if (firstPosition < lastPosition)
    {
        //Pivot is selected from the most central position
        int pivot = QSPartition(firstPosition,lastPosition,theArray);
        //Apply Quick Sort to other sections
        quickSort(firstPosition,pivot-1,theArray);
        quickSort(pivot+1,lastPosition,theArray);
    }
    return;
}

int QSPartition(int firstPosition,int lastPosition, int theArray[])
{
    int pivot = theArray[(firstPosition + lastPosition)/2];
    int leftInterator = firstPosition;
    int rightInterator = lastPosition;
    //While the first interator is less than or equal to the second interator
    while (leftInterator <= rightInterator)
    {
        //While this number is less than the pivot
        while (theArray[leftInterator] < pivot)
        {
            leftInterator++;
        }
        //While this number is greater than the pivot
        while (theArray[rightInterator] > pivot)
        {
            rightInterator--;
        }
        //If the left Interator position is a larger value than the right interator position
        if (leftInterator <= rightInterator)
        {
            SwapValues(leftInterator,rightInterator,theArray);
            //Increment/Decrement to carry on
            leftInterator++;
            rightInterator--;
        }
    }
    //Return this pivot to continue this process on the other subsets
    return leftInterator;
}

//NOt Finished
std::vector<int> mergeSort(std::vector<int> targetVector)
{
    //For assistance in finding a recursive method
    //https://www.princeton.edu/~achaney/tmve/wiki100k/docs/Merge_sort.html

    if (targetVector.size() <= 1)
    {
        //Return this as this is the smallest it can get
        return targetVector;
    }

    int middlePoint = targetVector.size()/2;

    std::vector<int> leftVector;
    std::vector<int> rightVector;
    std::vector<int> result;

    //Fill Left Vector
    for (unsigned int i = 0; i < middlePoint; i++)
    {
        leftVector.push_back(targetVector.at(i));
    }
    //Fill Right Vector
    for (unsigned int i = middlePoint; i < targetVector.size(); i++)
    {
        rightVector.push_back(targetVector.at(i));
    }

    leftVector = mergeSort(leftVector);
    rightVector = mergeSort(rightVector);
    result = Merge(leftVector,rightVector);

    printVector(result);

    return result;
}

std::vector<int> Merge(std::vector<int> leftVector, std::vector<int> rightVector)
{
    std::vector<int> result;

    //while (leftVector.size() == )

    return result;
}

void heapSort(int arraySize, int theArray[])
{
    Heap theHeap;
    //LOAD ALL THESE BAD ******** INTO AN ARRAY
    for (unsigned int i = 0; i < arraySize; i++)
    {
        //EXPLOSIIONS!!!!!!!!
        theHeap.Insert(theArray[i]);
    }
    //PLACE THEM BACK INTO THE ARRAY
    for (unsigned int i = 0; i < arraySize; i++)
    {
        theArray[i] = theHeap.Delete();
    }
    return;
}

void bucketSort(int arraySize,int theArray[])
{

}

//Prints the contents of an array
void printArray(int arraySize,int theArray[])
{
    //Prints every element of the array
    for (unsigned int i = 0; i < arraySize; i++)
    {
        std::cout << theArray[i] << " ";
    }
    return;
}

void printVector(std::vector<int> targetVector)
{
    for (unsigned int i = 0; i < targetVector.size(); i++)
    {
        std::cout << targetVector.at(i) << " ";
    }
    std::cout << std::endl;
    return;
}

//Swaps two values in an array
void SwapValues(int firstPosition,int secondPosition, int theArray[])
{
    //Swaps two positions in an array
    int savedValue = theArray[firstPosition];
    theArray[firstPosition] = theArray[secondPosition];
    theArray[secondPosition] = savedValue;
    return;
}

//Copies over the contents of an array
void copyArrayOver(int arraySize, int returnedArray[], int copyArray[])
{
    for (unsigned int i = 0; i < arraySize; i++)
    {
        returnedArray[i] = copyArray[i];
    }
    return;
}
