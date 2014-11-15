#include "adjancyMatrix.h"

adjancyMatrix::adjancyMatrix()
{
    matrix = NULL;
    directed = false;
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
                    //Create a new edge to be saved in the list
                    edge newEdge;
                    newEdge.addStartV(verticeList.at(i));
                    newEdge.addEndV(verticeList.at(h));
                    newEdge.setWeight(matrix[i*verticeList.size() + h]);
                    edgeList.push_back(newEdge);
                }
            }
        }
    }
    //We create a new vertex
    vertex * tempVertex = new vertex;
    tempVertex -> setName(newVertex);
    verticeList.push_back(tempVertex);
    rebuildMatrix();
    //Copy everything over again
    for (int row = 0; row < verticeList.size()-1; row++)
    {
        for (int column = 0; column < verticeList.size()-1; column++)
        {
            //For the list of edges
            for (int j = 0; j < edgeList.size(); j++)
            {   //If we are at the right position
                if ((edgeList.at(j).returnStartV() == verticeList.at(row)) &&
                    (edgeList.at(j).returnEndV() == verticeList.at(column)))
                {
                    matrix[row * verticeList.size() + column] = edgeList.at(j).returnWeight();
                    break;
                }
            }
        }
    }
    //Clear list for future usage
    edgeList.clear();

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
                int newWeight;
                std::cout << "Now the weight: ";
                std::cin >> newWeight;
                matrix[((verticeList.size()-1)*verticeList.size()) + i] = newWeight;
                if (directed == false)
                {
                    //Apply the attribute on the other vertex as well
                    matrix[(i * verticeList.size()) + verticeList.size()-1] = newWeight;
                }
                std::cout << "Connection Added" << std::endl;
                break;
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
                            edge newEdge;
                            newEdge.addStartV(verticeList.at(i));
                            newEdge.addEndV(verticeList.at(h));
                            newEdge.setWeight(matrix[i*verticeList.size() + h]);
                            edgeList.push_back(newEdge);
                        }
                    }
                }
            }
            //Remove and copy everything over by a node into the list
            for (int h = 0; h < verticeList.size()-1; h++)
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
                for (int column = 0; column < verticeList.size(); column++)
                {
                    //For the adjacent list
                    for (int j = 0; j < edgeList.size(); j++)
                    {
                        //If this is the right position
                        if ((edgeList.at(j).returnStartV() == verticeList.at(row)) &&
                        (edgeList.at(j).returnEndV() == verticeList.at(column)))
                        {
                            matrix[row * verticeList.size() + column] = edgeList.at(j).returnWeight();
                            break;
                        }
                    }
                    //Clear up the adjancy list of all vertices for future usage

                }
            }
            edgeList.clear();
            return;
        }
    }
    std::cout << "Vertex doesn't exist";
    return;
}

void adjancyMatrix::breadthFirst(std::string start)
{
    for (int i = 0; i < verticeList.size(); i++)
    {
        //If we find the start node
        if (verticeList.at(i) -> returnName() == start)
        {
            //Starting with this node
            std::vector<vertex*> masterList;
            masterList.push_back(verticeList.at(i));
            int savedLocation = i;
            for (int q = 0; q < masterList.size(); q++)
            {
                std::cout << masterList.at(q) -> returnName() << " -> ";
                masterList.at(q) -> setVisitFlag(true);
                //Find actual location in list
                for (int d = 0; d < verticeList.size(); d++)
                {
                    if (verticeList.at(d) == masterList.at(q))
                    {
                        savedLocation = d;
                    }
                }
                //For every column in that list
                for (int h = 0; h < verticeList.size(); h++)
                {
                    //If there is a connection here
                    if (matrix[(savedLocation*verticeList.size())+h] != 0)
                    {
                        if (verticeList.at(h) -> wasVisited() == false)
                        {
                            masterList.push_back(verticeList.at(h));
                        }
                    }
                }
            }
            std::cout << "END" << std::endl;
            //Reset visit flag for future traversals
            for (int h = 0; h < verticeList.size(); h++)
            {
                verticeList.at(i) -> setVisitFlag(false);
            }
            break;
        }
        //This is in case the vertex doesn't exist
        else if (i == verticeList.size()-1)
        {
            std::cout << "Vertex not found. Cannot traverse." << std::endl;
        }
    }
}

void adjancyMatrix::depthFirst(std::string start)
{
    for (int i = 0; i < verticeList.size(); i++)
    {
        //If we find the start node
        if (verticeList.at(i) -> returnName() == start)
        {
            depthTraverse(i);
            std::cout << "END" << std::endl;
            //Reset for future traversals
            for (int h = 0; h < verticeList.size(); h++)
            {
                verticeList.at(i) -> setVisitFlag(false);
            }
            break;
        }
        //This is in case the vertex doesn't exist
        else if (i == verticeList.size()-1)
        {
            std::cout << "Vertex not found. Cannot traverse." << std::endl;
        }
    }
    return;
}

void adjancyMatrix::depthTraverse(int rowNumber)
{
    std::cout << verticeList.at(rowNumber) -> returnName() << " -> ";
    verticeList.at(rowNumber) -> setVisitFlag(true);
    for (int i = 0; i < verticeList.size(); i++)
    {
        //If there is a connection here
        if (matrix[(rowNumber*verticeList.size())+i] != 0)
        {
            //If this wasn't visited yet
            if (verticeList.at(i) -> wasVisited() == false)
            {
                depthTraverse(i);
            }
        }
    }
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

void adjancyMatrix::setDirected(bool statement)
{
    directed = statement;
}

void adjancyMatrix::Dijkstra(std::string start, std::string End)
{
    //Find the starting location
    vertex * startingVertex = NULL;
    int savedLocation;
    for (int i = 0; i < verticeList.size(); i++)
    {
        if (verticeList.at(i) -> returnName() == start)
        {
            startingVertex = verticeList.at(i);
            savedLocation = i;
            break;
        }
    }
    std::vector<graphSegment> graphMatrix;
    for (int i = 0; i < verticeList.size(); i++)
    {
        graphSegment newSegment;
        newSegment.pointer = verticeList.at(i);
        newSegment.position = i;
        newSegment.previousPointer = NULL;
        newSegment.totalWeight = 1000000;
        graphMatrix.push_back(newSegment);
    }

    //As long as we have our start location
    if (startingVertex != NULL)
    {
        //Add starting location to queue
        std::vector<graphSegment> vertexQueue;
        graphMatrix.at(savedLocation).totalWeight = 0;
        vertexQueue.push_back(graphMatrix.at(savedLocation));
        vertexQueue.at(savedLocation).pointer -> setVisitFlag(true);
        //While there are still things on the queue
        for (int i = 0; i < vertexQueue.size(); i++)
        {
            //Investigate all the adjacent nodes
            for (int column = 0; column < verticeList.size(); column++)
            {
                //If there is a connection
                if (matrix[vertexQueue.at(i).position*verticeList.size() + column] != 0)
                {
                    //Determine if this is cheaper than the previous listed in the chart
                    int currentWeight = matrix[vertexQueue.at(i).position*verticeList.size() + column]
                        + graphMatrix.at(vertexQueue.at(i).position).totalWeight;
                    if (currentWeight < graphMatrix.at(column).totalWeight)
                    {
                        graphMatrix.at(column).totalWeight = currentWeight;
                        graphMatrix.at(column).previousPointer = graphMatrix.at(i).pointer;
                    }
                    //If we can evaluate this next, do so
                    if (graphMatrix.at(column).pointer -> wasVisited() != true)
                    {
                        vertexQueue.push_back(graphMatrix.at(column));
                        graphMatrix.at(column).pointer -> setVisitFlag(true);
                    }
                }
            }
        }/*
        for (int i = 0; i < graphMatrix.size(); i++)
        {
            std::cout << graphMatrix.at(i).totalWeight << " ";
        }*/

        //Now we shall return the order that the user must traverse to get the minimum amount of weight
        for (int i = 0; i < graphMatrix.size(); i++)
        {
            if (graphMatrix.at(i).pointer -> returnName() == End)
            {
                vertex * currentPointer = graphMatrix.at(i).previousPointer;
                std::string outputString = graphMatrix.at(i).pointer -> returnName();
                savedLocation = i;
                while (currentPointer != startingVertex)
                {
                    currentPointer = graphMatrix.at(savedLocation).previousPointer;
                    outputString = currentPointer -> returnName() + " " + outputString;
                    for (int d = 0; d < graphMatrix.size(); d++)
                    {
                        if (currentPointer == graphMatrix.at(d).pointer)
                        {
                            savedLocation = d;
                            break;
                        }
                    }
                }
                std::cout << "Weight: " << graphMatrix.at(i).totalWeight << std::endl;
                std::cout << outputString << std::endl;
                break;
            }
        }
        resetVisitFlags();
        return;
    }
    std::cout << "Vertex not found." << std::endl;
}

void adjancyMatrix::resetVisitFlags()
{
    for (int i = 0; i < verticeList.size(); i++)
    {
        verticeList.at(i) -> setVisitFlag(false);
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
