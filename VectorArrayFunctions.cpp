#include "VectorArrayFunctions.h"

/*
    Author: Aaron Martin
    Created 4/25/2014
    Modified: ---------
*/

#include <iostream>

//------------------------VECTOR FUNCTIONS------------------------------------

//Removes a given unit from the vector and returns the new vector
template <typename T>
std::vector<T> removePositionVector(int position, std::vector<T> targetVector)
{
    //This will be the vector returned
    std::vector<T> returnedVector;
    //Travel through the vector starting from the end
    for (unsigned int i = 0; i < targetVector.size(); i++)
    {
        if (i != position)
        {
            //Save the value
            T item = targetVector.at(i);
            //Then push it on the returned Vector
            returnedVector.push_back(item);
        }
        else
        {
            //Do nothing and ignore this position
        }
    }
    //Return Vector
    return returnedVector;
}

//Prints the Contents of the Vector
template <typename T>
void printVector(std::vector<T> targetVector)
{
    //Travels through Vector
    for (unsigned int i = 0; i < targetVector.size(); i++)
    {
        //Print Unit
        std::cout << targetVector.at(i) << std::endl;
    }
    //End Function
    return;
}

//Add a number of units to the vector
template <typename T>
void multiVectorPush(std::vector<T> &targetVector, T data, int NumberOfPushes)
{
    //Adds each unit
    for (unsigned int i = 0; i < NumberOfPushes; i++)
    {
        //Pushes unit onto Vector
        targetVector.push_back(data);
    }
    //End Function
    return;
}

//Reverses the order of the contents in the Vector
template <typename T>
std::vector<T> reverseVector(std::vector<T> targetVector)
{
    //Returned Vector
    std::vector<T> reversedVector;

    //Starting from the end, finds last position in vector
    for (unsigned int i = (targetVector.size() - 1); i >= 0; i--)
    {
        //Grabs the data
        T item = targetVector.at(i);
        //Pushes it onto the new vector
        reversedVector.push_back(item);
    }

    //Returns reversed Vector
    return reversedVector;
}

//-------------------------ARRAY FUNCTIONS------------------------------------

//Fills all the units in a 1 dimensional array with the given data type
template <typename T>
void fillArray(T theArray[], T dataFiller,int arraySize)
{
    //Travels through the array
    for (unsigned int i = 0; i < arraySize; i++)
    {
        //Sets the current position equal to designated data
        theArray[i] = dataFiller;
    }
    //End Function
    return;
}

//Prints the contents of the Array in the command prompt
template <typename T>
void printArray(T theArray[], int arraySize)
{
    //Travels through the array
    for (unsigned int i = 0; i < arraySize; i++)
    {
        //Print data in position
        std::cout << theArray[i] << std::endl;
    }
    //End Function
    return;
}
