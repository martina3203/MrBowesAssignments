#ifndef ADJANCYMATRIX_H
#define ADJANCYMATRIX_H

#include "vertex.h"
#include "edge.h"
#include <iostream>
#include <iomanip>

class adjancyMatrix
{
    public:
        adjancyMatrix();
        virtual ~adjancyMatrix();
        void addVertex(std::string);
        void removeVertex(std::string);
        void breadthFirst(std::string);
        void depthFirst(std::string);
        void printVertices();
        void setDirected(bool);
        void Dijkstra(std::string);
    protected:
    private:
        void rebuildMatrix();
        void depthTraverse(int);
        void breadthTraverse(int);
        std::vector<vertex*> verticeList;
        std::vector<edge> edgeList;
        int * matrix;
        bool directed;
};

#endif // ADJANCYMATRIX_H
