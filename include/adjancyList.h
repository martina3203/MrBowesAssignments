#ifndef ADJANCYLIST_H
#define ADJANCYLIST_H

#include "vertex.h"
#include "edge.h"
#include <iostream>
#include <iomanip>


class adjancyList
{
    public:
        adjancyList();
        void addVertex(std::string);
        void removeVertex(std::string);
        void depthFirst(std::string);
        void breadthFirst(std::string);
        void printList();
        void setDirected(bool);
        void Dijkstra(std::string);
        void Prim(std::string);
        void Kruskal();
        void findPath(std::string,std::string);
        virtual ~adjancyList();
    protected:
    private:
        std::vector<vertex*> theList;
        std::vector< std::vector<edge> > edgeList;
        std::vector<graphSegment> graphChart;
        void depthTraversal(vertex*);
        void resetVisitFlags();
        bool directed;
};

#endif // ADJANCYLIST_H
