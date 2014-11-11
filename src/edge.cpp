#include "edge.h"

edge::edge()
{
    startingVertex = NULL;
    endingVertex = NULL;
    weight = 1; //default weight for any edge
}

void edge::addStartV(vertex* start)
{
    startingVertex = start;
}

void edge::addEndV(vertex* ending)
{
    endingVertex = ending;
}

void edge::setWeight(int newWeight)
{
    weight = newWeight;
}

vertex * edge::returnStartV(vertex*)
{
    return startingVertex;
}


vertex * edge::returnEndV(vertex*)
{
    return endingVertex;
}

int edge::returnWeight()
{
    return weight;
}

edge::~edge()
{

}
