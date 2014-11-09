#include "adjancyMatrix.h"

adjancyMatrix::adjancyMatrix()
{
    matrix = NULL;
    directed = false;
    weighted = false;
}

void adjancyMatrix::addVertex(std::string newVertex)
{
    //Save all previous values to be exported to new matrix
    if (matrix != NULL)
    {
        //Save connections into the vertices
        for (int i = 0; i < verticeList.size(); i++)
        {
            for (int h = 0; h < verticeList.size(); h++)
            {
                //If there is a connection between these two vertices
                if (matrix[i * verticeList.size() + h] != 0)
                {
                    //Save in that list
                    verticeList.at(i) -> addToAdjacentList(verticeList.at(h));
                }
            }
        }
    }
    vertex * tempVertex = new vertex;
    tempVertex -> setName(newVertex);
    verticeList.push_back(tempVertex);
    rebuildMatrix();
    //Copy everything over again
    for (int row = 0; row < verticeList.size()-1; row++)
    {
        std::vector<vertex*> adjacent = verticeList.at(row) -> returnAdjacentList();
        for (int column = 0; column < verticeList.size()-1; column++)
        {
            //For the adjacent list
            for (int j = 0; j < adjacent.size(); j++)
            {
                if (adjacent.at(j) == verticeList.at(column))
                {
                    matrix[row * verticeList.size() + column] = 1;
                    break;
                }
            }
            //Clear up the adjancy list of all vertices for future usage
            verticeList.at(row) -> clearList();
        }
    }

    std::string input;
    while (input != "QUIT")
    {
        std::cout << "List any adjacent nodes for " << newVertex << ". Terminate with QUIT." << std::endl;
        std::cin >> input;
        for (int i = 0; i < verticeList.size()-1; i++)
        {
            if (input == "QUIT")
            {
                break;
            }
            else if (verticeList.at(i) -> returnName() == input)
            {
                //This has to be the last column of the matrix as this was the insertion
                matrix[((verticeList.size()-1)*verticeList.size()) + i] = 1;
                if (directed == false)
                {
                    //Apply the attribute on the other vertex as well
                    matrix[(i * verticeList.size()) + verticeList.size()-1] = 1;
                }
                std::cout << "Connection Added" << std::endl;
            }
            else if (i == verticeList.size()-2)
            {
                std::cout << "Vertex not found" << std::endl;
            }
        }
    }

    return;
}

void adjancyMatrix::removeVertex(std::string targetVertex)
{
    for (int i = 0; i < verticeList.size(); i++)
    {
        if (verticeList.at(i) -> returnName() == targetVertex)
        {
            vertex * currentVertex = verticeList.at(i);
            //Save a copy of the matrix
            for (int i = 0; i < verticeList.size(); i++)
            {
                for (int h = 0; h < verticeList.size(); h++)
                {
                    //If there is a connection between these two vertices
                    if (matrix[i * verticeList.size() + h] != 0)
                    {
                        //Save in that list if it's not the vertex being deleted
                        if (verticeList.at(h) -> returnName() != targetVertex)
                        {
                            verticeList.at(i) -> addToAdjacentList(verticeList.at(h));
                        }
                    }
                }
            }
            //Remove and copy everything over by a node into the list
            for (int h = i; h < verticeList.size()-1; h++)
            {
                //Move up the list
                verticeList.at(h) = verticeList.at(h+1);
            }
            delete currentVertex;
            currentVertex = NULL;
            verticeList.pop_back();
            //Copy matrix back over
            rebuildMatrix();
            for (int row = 0; row < verticeList.size(); row++)
            {
                std::vector<vertex*> adjacent = verticeList.at(row) -> returnAdjacentList();
                for (int column = 0; column < verticeList.size(); column++)
                {
                    //For the adjacent list
                    for (int j = 0; j < adjacent.size(); j++)
                    {
                        if (adjacent.at(j) == verticeList.at(column))
                        {
                            matrix[row * verticeList.size() + column] = 1;
                            break;
                        }
                    }
                    //Clear up the adjancy list of all vertices for future usage
                    verticeList.at(row) -> clearList();
                }
            }
            return;
        }
    }
    std::cout << "Vertex doesn't exist";
    return;
}

void adjancyMatrix::rebuildMatrix()
{
    //This simply resets the state of the array
    delete matrix;
    matrix = NULL;

    //Found on stack overflow. Make a single dimensional array with X * Y spots.
    //When accessing it's DesiredRow * #OfColumns + DesiredColumn
    int arraySize = verticeList.size() * verticeList.size();
    matrix = new int [arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        matrix[i] = 0;
    }
    return;
}

void adjancyMatrix::printVertices()
{
    for (int i = 0; i < verticeList.size(); i++)
    {
        std::cout << std::setw(10);
        std::cout << verticeList.at(i) -> returnName() << " ";
        for (int h = 0; h < verticeList.size(); h++)
        {
            std::cout << matrix[i * verticeList.size() + h] << " ";
        }
        std::cout << std::endl;
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
