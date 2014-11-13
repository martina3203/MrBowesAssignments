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
        virtual ~adjancyList();
    protected:
    private:
        std::vector<vertex*> theList;
        std::vector< std::vector<edge> > edgeList;
        void depthTraversal(vertex*);
        bool directed;
};

#endif // ADJANCYLIST_H
