#ifndef VECTORARRAYFUNCTIONS_H
#define VECTORARRAYFUNCTIONS_H

/*
    Author: Aaron Martin
    Created 4/25/2014
    Modified: ---------
*/

#include <vector>

//------------------------VECTOR FUNCTIONS------------------------------------

//Removes a given unit from the vector and returns the new vector
template <typename T>
std::vector<T> removePositionVector(int position, std::vector<T> targetVector);

//Prints the Contents of the Vector
template <typename T>
void printVector(std::vector<T> targetVector);

//Add a number of units to the vector
template <typename T>
void multiVectorPush(std::vector<T> &targetVector, T data,int NumberOfPushes);

//Reverses the order of the contents in the Vector
template <typename T>
std::vector<T> reverseVector(std::vector<T> targetVector);

//------------------------ARRAY FUNCTIONS------------------------------------

//Fills all the units in a 1 dimensional array with the given data type
template <typename T>
void fillArray(T theArray[], T dataFiller,int arraySize);

//Prints the contents of the Array in the command prompt
template <typename T>
void printArray(T theArray[], int arraySize);

#endif // VECTORARRAYFUNCTIONS
