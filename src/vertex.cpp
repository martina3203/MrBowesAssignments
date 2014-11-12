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
