#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap
{
    public:
        Heap();
        virtual ~Heap();
        void Insert(int);
        int Delete();
        void printHeap();
    protected:
    private:
        void rescale();
        void compareAndSwitch(int);
        void childComparison(int);
        int * arrayPointer;
        int arraySize;

};


class PriorityQueue
{
    public:
        PriorityQueue();
        virtual ~PriorityQueue();
        void Insert(int);
        int Delete();
        void printQueue();
    protected:
    private:
        void rescale();
        void compareAndSwitch(int);
        void childComparison(int);
        int * arrayPointer;
        int arraySize;
};


#endif // HEAP_H
