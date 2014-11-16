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

void adjancyMatrix::Dijkstra(std::string start)
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
    graphChart.clear();
    for (int i = 0; i < verticeList.size(); i++)
    {
        graphSegment newSegment;
        newSegment.pointer = verticeList.at(i);
        newSegment.position = i;
        newSegment.previousPointer = NULL;
        newSegment.totalWeight = 1000000;
        graphChart.push_back(newSegment);
    }

    //As long as we have our start location
    if (startingVertex != NULL)
    {
        //Add starting location to queue
        std::vector<graphSegment> vertexQueue;
        graphChart.at(savedLocation).totalWeight = 0;
        vertexQueue.push_back(graphChart.at(savedLocation));
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
                        + graphChart.at(vertexQueue.at(i).position).totalWeight;
                    if (currentWeight < graphChart.at(column).totalWeight)
                    {
                        graphChart.at(column).totalWeight = currentWeight;
                        graphChart.at(column).previousPointer = graphChart.at(i).pointer;
                    }
                    //If we can evaluate this next, do so
                    if (graphChart.at(column).pointer -> wasVisited() != true)
                    {
                        vertexQueue.push_back(graphChart.at(column));
                        graphChart.at(column).pointer -> setVisitFlag(true);
                    }
                }
            }
        }
    }
}

void adjancyMatrix::Prim(std::string start)
{
    int startLocation;
    //Find starting location
    for (int i = 0; i < verticeList.size(); i++)
    {
        if (verticeList.at(i) -> returnName() == start)
        {
            startLocation = i;
            verticeList.at(i) -> setVisitFlag(true);
        }
    }
    graphChart.clear();
    //Rebuild the graph to read information from
    for (int i = 0; i < verticeList.size(); i++)
    {
        graphSegment newSegment;
        newSegment.pointer = verticeList.at(i);
        newSegment.position = i;
        newSegment.previousPointer = NULL;
        newSegment.totalWeight = 1000000;
        graphChart.push_back(newSegment);
    }
    //With the starting vertex, find it's edges and add to queue
    std::vector<edge> edgeQueue;
    for (int i = 0; i < verticeList.size(); i++)
    {
        if (matrix[startLocation * verticeList.size() + i] != 0)
        {
            edge possibleEdge;
            possibleEdge.addStartV(verticeList.at(startLocation));
            possibleEdge.addEndV(verticeList.at(i));
            possibleEdge.setWeight(matrix[startLocation*verticeList.size()+i]);
            edgeQueue.push_back(possibleEdge);
        }
    }
    //While there is stuff in the queue
    while (edgeQueue.size() != 0)
    {
        int smallestEdge = 1000000;
        vertex * vertexConnectedToEdge = NULL;
        vertex * previousPointer = NULL;
        for (int i = 0; i < edgeQueue.size(); i++)
        {
            if (edgeQueue.at(i).returnWeight() < smallestEdge)
            {
                smallestEdge = edgeQueue.at(i).returnWeight();
                vertexConnectedToEdge = edgeQueue.at(i).returnEndV();
                previousPointer = edgeQueue.at(i).returnStartV();
            }
        }
        //The smallest edge is now added to the graph
        for (int i = 0; i < verticeList.size(); i++)
        {
           if (vertexConnectedToEdge == verticeList.at(i))
           {
               startLocation = i;
               vertexConnectedToEdge -> setVisitFlag(true);
               graphChart.at(i).previousPointer = previousPointer;
               graphChart.at(i).totalWeight = graphChart.at(startLocation).totalWeight + smallestEdge;
           }
        }
        //Add any new vertices that the edge opened up
        for (int i = 0; i < verticeList.size(); i++)
        {
            if (matrix[startLocation * verticeList.size() + i] != 0)
            {
                edge possibleEdge;
                possibleEdge.addStartV(verticeList.at(startLocation));
                possibleEdge.addEndV(verticeList.at(i));
                possibleEdge.setWeight(matrix[startLocation*verticeList.size()+i]);
                edgeQueue.push_back(possibleEdge);
            }
        }
        //Remove any edges that involve that a vertex that is already included in the graph
        std::vector<edge> newQueue;
        for (int i = 0; i < edgeQueue.size(); i++)
        {
            if (edgeQueue.at(i).returnEndV() -> wasVisited() != true)
            {
                newQueue.push_back(edgeQueue.at(i));
            }
        }
        edgeQueue = newQueue;
    }
    resetVisitFlags();
}

void adjancyMatrix::Kruskal()
{
    //Collect all the edges
    std::vector <edge> KruskalEdgeList;
    for (int i = 0; i < verticeList.size(); i++)
    {
        for (int j = 0; j < verticeList.size(); j++)
        {
            if (matrix[i * verticeList.size() + j] != 0)
            {
                edge possibleEdge;
                possibleEdge.addStartV(verticeList.at(i));
                possibleEdge.addEndV(verticeList.at(j));
                possibleEdge.setWeight(matrix[i*verticeList.size() + j]);
                KruskalEdgeList.push_back(possibleEdge);
            }
        }
    }
    //Sort edges
    for (int i = 0; i < KruskalEdgeList.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (KruskalEdgeList.at(j).returnWeight() < KruskalEdgeList.at(j-1).returnWeight())
            {
                edge temp = KruskalEdgeList.at(j);
                KruskalEdgeList.at(j) = KruskalEdgeList.at(j-1);
                KruskalEdgeList.at(j-1) = temp;
            }
        }
    }

    int minimumWeight = 0;
    std::vector<edge> resultingTree;
    KruskalEdgeList.at(0).returnStartV() -> setVisitFlag(true);
    //Determine which edges to add to the new tree
    for (int i = 0; i < KruskalEdgeList.size(); i++)
    {
        if (KruskalEdgeList.at(i).returnEndV() -> wasVisited() == false)
        {
            resultingTree.push_back(KruskalEdgeList.at(i));
            KruskalEdgeList.at(i).returnEndV() -> setVisitFlag(true);
        }
    }
    resetVisitFlags();
    //Prints the tree
    std::cout << "Resultant Tree: ";
    for (int i = 0; i < resultingTree.size(); i++)
    {
        std::cout << resultingTree.at(i).returnStartV() -> returnName() << "->";
        std::cout << resultingTree.at(i).returnEndV() -> returnName() << " ";
    }
    std::cout << std::endl;
}

void adjancyMatrix::findPath(std::string start, std::string End)
{
    vertex * startingVertex = NULL;
    for (int i = 0; i < graphChart.size(); i++)
    {
        if (graphChart.at(i).pointer -> returnName() == start)
        {
            startingVertex = graphChart.at(i).pointer;
        }
    }

    if (startingVertex == NULL)
    {
        std::cout << "Starting Vertex not found" << std::endl;
        return;
    }

    for (int i = 0; i < graphChart.size(); i++)
    {
        if (graphChart.at(i).pointer -> returnName() == End)
        {
            vertex * currentPointer = graphChart.at(i).previousPointer;
            std::string outputString = graphChart.at(i).pointer -> returnName();
            int savedLocation = i;
            while (currentPointer != startingVertex)
            {
                currentPointer = graphChart.at(savedLocation).previousPointer;
                if (currentPointer != NULL)
                {
                    outputString = currentPointer -> returnName() + " " + outputString;
                    for (int d = 0; d < graphChart.size(); d++)
                    {
                        if (currentPointer == graphChart.at(d).pointer)
                        {
                            savedLocation = d;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            std::cout << "Weight: " << graphChart.at(i).totalWeight << std::endl;
            std::cout << outputString << std::endl;
            return;
        }
    }
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
