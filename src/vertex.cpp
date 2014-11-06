#include "vertex.h"

vertex::vertex()
{
    X = 0;
    Y = 0;
}

void vertex::setName(std::string newName)
{
    vertexName = newName;
}

std::string vertex::returnName()
{
    return vertexName;
}

void vertex::addToAdjacentList(vertex* adjacent)
{
    adjacentList.push_back(adjacent);
}

std::vector<vertex*> vertex::returnAdjacentList()
{
    return adjacentList;
}

void vertex::clearList()
{
    adjacentList.clear();
}

vertex::~vertex()
{

}
