#include "vertex.h"

vertex::vertex()
{
    visited = false;
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

bool vertex::wasVisited()
{
    return visited;
}

void vertex::setVisitFlag(bool newState)
{
    visited = newState;
}

vertex::~vertex()
{

}
