#include "adjancyMatrix.h"

adjancyMatrix::adjancyMatrix()
{
    matrix = NULL;
}

void adjancyMatrix::addVertex(std::string newVertex, std::vector<std::string> adjacentV)
{
    vertex * tempVertex = new vertex;
    if (matrix == NULL)
    {
        //Create a matrix that supports two elements intially
        matrix = new int[2][2];
    }
}

adjancyMatrix::~adjancyMatrix()
{
    //Remove Matrix
    if (matrix != NULL)
    {
        delete matrix;
    }
    //Clear any vertex pointers left over
    for (int i = 0; i < verticeList.size(); i++)
    {
        if (verticeList.at(i) != NULL)
        {
            delete verticeList.at(i);
            verticeList.at(i) = NULL;
        }
    }
}
