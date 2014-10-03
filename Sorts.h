#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>

void selectionSort(int arraySize,int theArray[]);

void insertionSort(int arraySize,int theArray[]);

void bubbleSort(int arraySize,int theArray[]);

void shellSort(int arraySize,int theArray[]);

void quickSort(int firstPosition,int lastPosition, int theArray[]);

int QSPartition(int firstPosition,int lastPosition, int theArray[]);

std::vector<int> mergeSort(std::vector<int> targetVector);

std::vector<int> Merge(std::vector<int> leftVector, std::vector<int> rightVector);

void heapSort(int arraySize,int theArray[]);

void bucketSort(int arraySize,int theArray[]);

void printArray(int arraySize,int theArray[]);

void printVector(std::vector<int> targetVector);

void SwapValues(int firstPosition, int secondPosition, int theArray[]);

void copyArrayOver(int arraySize, int returnedArray[], int copyArray[]);

#endif // SORTS_H
