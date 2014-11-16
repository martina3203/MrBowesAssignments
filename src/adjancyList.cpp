#include "adjancyList.h"

adjancyList::adjancyList()
{
    directed = false;
}

void adjancyList::addVertex(std::string vertexName)
{
    vertex * newVertex = new vertex;
    newVertex -> setName(vertexName);

    theList.push_back(newVertex);
    //Add Connections
    std::string input;
    //Adds a new column to store all the new edges
    std::vector<edge> newEdgeListForVertex;
    edgeList.push_back(newEdgeListForVertex);
    while (input != "QUIT")
    {
        std::cout << "List any adjacent nodes for " << vertexName << ". Terminate with QUIT." << std::endl;
        std::cin >> input;
        for (int i = 0; i < theList.size()-1; i++)
        {
            if (input == "QUIT")
            {
                break;
            }
            else if (theList.at(i) -> returnName() == input)
            {
                int newWeight;
                std::cout << "Now the weight: ";
                std::cin >> newWeight;
                //Add as an adjacent node
                edge newEdge;
                newEdge.addStartV(newVertex);
                newEdge.addEndV(theList.at(i));
                newEdge.setWeight(newWeight);
                edgeList.at(edgeList.size()-1).push_back(newEdge);
                if (directed == false)
                {
                    //Apply the attribute on the other vertex as well
                    newEdge.addStartV(theList.at(i));
                    newEdge.addEndV(newVertex);
                    newEdge.setWeight(newWeight);
                    edgeList.at(i).push_back(newEdge);
                }
                std::cout << "Connection Added." << std::endl;
                break;
            }
            else if (i == theList.size()-2)
            {
                std::cout << "Vertex not found." << std::endl;
            }
        }
    }
    return;
}

void adjancyList::removeVertex(std::string targetVertex)
{
    for (int i = 0; i < theList.size(); i++)
    {
        //Found the vertex
        if (theList.at(i) -> returnName() == targetVertex)
        {
            vertex * removedVertex = theList.at(i);
            //Clean up any nodes that also have a edge with this vertex
            for (int h = 0; h < theList.size(); h++)
            {
                //Obtain and clear list for replacement list
                std::vector<edge> currentEdgeList = edgeList.at(h);
                std::vector<edge> updatedEdgeList;
                for (int d = 0; d < currentEdgeList.size(); d++)
                {
                    //Add it back on if it's ok
                    if (currentEdgeList.at(d).returnStartV() != removedVertex)
                    {
                        updatedEdgeList.push_back(currentEdgeList.at(d));
                    }
                }
                //Copy over the list
                edgeList.at(h) = updatedEdgeList;
            }
            //Finally, update the list to remove this node
            std::vector<vertex*> replacementList = theList;
            theList.clear();
            for (int h = 0; h < replacementList.size(); h++)
            {
                //If this is anything but the vertex to remove
                if (replacementList.at(h) != removedVertex)
                {
                    theList.push_back(replacementList.at(h));
                }
            }
            return;
        }
    }
    std::cout << "Vertex not found" << std::endl;
}

void adjancyList::depthFirst(std::string start)
{
    for (int i = 0; i < theList.size(); i++)
    {
        if (theList.at(i) -> returnName() == start)
        {
            depthTraversal(theList.at(i));
            std::cout << "END" << std::endl;
            for (int h = 0; h < theList.size(); h++)
            {
                theList.at(i) -> setVisitFlag(false);
            }
            return;
        }
    }
    std::cout << "Vertex does not exist." << std::endl;
}

void adjancyList::depthTraversal(vertex * start)
{
    std::cout << start -> returnName() << " -> ";
    start -> setVisitFlag(true);
    /*
    for (int i = 0; i < edgeList.size(); i++)
    {
        if (edgeList.at(i) -> wasVisited() == false)
        {
            depthTraversal(adjancent.at(i));
        }
    }
    */
    return;
}

void adjancyList::breadthFirst(std::string start)
{
    for (int i = 0; i < theList.size(); i++)
    {
        //If we find the start node
        if (theList.at(i) -> returnName() == start)
        {
            //Starting with this node
            std::vector<vertex*> masterList;
            masterList.push_back(theList.at(i));
            for (int q = 0; q < masterList.size(); q++)
            {
                std::cout << masterList.at(q) -> returnName() << " -> ";
                masterList.at(q) -> setVisitFlag(true);/*
                for (int d = 0; d < adjacent.size(); d++)
                {
                    if (adjacent.at(d) -> wasVisited() ==  false)
                    {
                        masterList.push_back(adjacent.at(d));
                        adjacent.at(q) -> setVisitFlag(true);
                    }
                }*/
            }
            std::cout << "END" << std::endl;
            //Reset visit flag for future traversals
            for (int h = 0; h < theList.size(); h++)
            {
                theList.at(i) -> setVisitFlag(false);
            }
            return;
        }
    }

    std::cout << "Vertex does not exist." << std::endl;
}

void adjancyList::printList()
{
    for (int i = 0; i < theList.size(); i++)
    {
        std::cout << theList.at(i) -> returnName() << std::endl;
        std::vector<edge> edgesVector = edgeList.at(i);
        for (int i = 0; i < edgesVector.size(); i++)
        {
            std::cout << edgesVector.at(i).returnEndV() -> returnName();
        }
        std::cout << std::endl;
    }
}

void adjancyList::setDirected(bool statement)
{
    directed = statement;
}

void adjancyList::Dijkstra(std::string start)
{
    vertex * startingVertex = NULL;
    int savedLocation;
    for (int i = 0; i < theList.size(); i++)
    {
        if (theList.at(i) -> returnName() == start)
        {
            startingVertex = theList.at(i);
            savedLocation = i;
            break;
        }
    }
    graphChart.clear();
    for (int i = 0; i < theList.size(); i++)
    {
        graphSegment newSegment;
        newSegment.pointer = theList.at(i);
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
            int currentPosition = vertexQueue.at(i).position;
            for (int column = 0; column < edgeList.at(currentPosition).size(); column++)
            {
                    //Determine if this is cheaper than the previous listed in the chart
                    int currentWeight = graphChart.at(currentPosition).totalWeight +
                        edgeList.at(currentPosition).at(column).returnWeight();
                    for (int r = 0; r < theList.size(); r++)
                    {
                        if (theList.at(r) == edgeList.at(currentPosition).at(column).returnEndV())
                        {
                            savedLocation = r;
                            break;
                        }
                    }
                    if (currentWeight < graphChart.at(savedLocation).totalWeight)
                    {
                        graphChart.at(savedLocation).totalWeight = currentWeight;
                        graphChart.at(savedLocation).previousPointer = graphChart.at(currentPosition).pointer;
                    }
                    //If we can evaluate this next, do so
                    if (graphChart.at(savedLocation).pointer -> wasVisited() != true)
                    {
                        vertexQueue.push_back(graphChart.at(savedLocation));
                        graphChart.at(savedLocation).pointer -> setVisitFlag(true);
                    }
            }
        }
        return;
    }
    std::cout << "Vertex not found." << std::endl;
}

void adjancyList::Prim(std::string start)
{

}

void adjancyList::Kruskal()
{
    //Collect Edges
    std::vector <edge> KruskalEdgeList;
    for (int i = 0; i < edgeList.size(); i++)
    {
        for (int j = 0; j < edgeList.at(i).size(); j++)
        {
            KruskalEdgeList.push_back(edgeList.at(i).at(j));
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

void adjancyList::resetVisitFlags()
{
    for (int i = 0; i < theList.size(); i++)
    {
        theList.at(i) -> setVisitFlag(false);
    }
}

void adjancyList::findPath(std::string start, std::string End)
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

adjancyList::~adjancyList()
{
    //dtor
}
