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
                //Add as an adjacent node
                newVertex -> addToAdjacentList(theList.at(i));
                if (directed == false)
                {
                    //Apply the attribute on the other vertex as well
                    theList.at(i) -> addToAdjacentList(newVertex);
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
                std::vector<vertex*> adjacentList = theList.at(h) -> returnAdjacentList();
                theList.at(h) -> clearList();
                for (int d = 0; d < adjacentList.size(); d++)
                {
                    //Add it back on if it's ok
                    if (adjacentList.at(d) != theList.at(i))
                    {
                        theList.at(h) -> addToAdjacentList(adjacentList.at(d));
                    }
                }
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
    std::vector<vertex*> adjancent = start -> returnAdjacentList();
    for (int i = 0; i < adjancent.size(); i++)
    {
        if (adjancent.at(i) -> wasVisited() == false)
        {
            depthTraversal(adjancent.at(i));
        }
    }
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
                masterList.at(q) -> setVisitFlag(true);
                std::vector<vertex*> adjacent = masterList.at(q) -> returnAdjacentList();
                for (int d = 0; d < adjacent.size(); d++)
                {
                    if (adjacent.at(d) -> wasVisited() ==  false)
                    {
                        masterList.push_back(adjacent.at(d));
                    }
                }
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
    }
}

adjancyList::~adjancyList()
{
    //dtor
}
