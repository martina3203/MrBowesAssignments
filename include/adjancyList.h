#ifndef ADJANCYLIST_H
#define ADJANCYLIST_H

#include "vertex.h"
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
        virtual ~adjancyList();
    protected:
    private:
        std::vector<vertex*> theList;
        void depthTraversal(vertex*);
        bool directed;

};

#endif // ADJANCYLIST_H
