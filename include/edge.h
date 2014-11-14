#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class edge
{
    public:
        edge();
        virtual ~edge();
        void addStartV(vertex*);
        void addEndV(vertex*);
        void setWeight(int);
        vertex * returnStartV();
        vertex * returnEndV();
        int returnWeight();
    protected:
    private:
        vertex * startingVertex;
        vertex * endingVertex;
        int weight;
};

class graphSegment
{
public:
    vertex * pointer;
    int position;
    vertex * previousPointer;
    int totalWeight;
};

#endif // EDGE_H
