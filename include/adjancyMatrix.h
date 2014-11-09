#ifndef ADJANCYMATRIX_H
#define ADJANCYMATRIX_H

#include "vertex.h"
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
    protected:
    private:
        void rebuildMatrix();
        void depthTraverse(int);
        void breadthTraverse(int);
        std::vector<vertex*> verticeList;
        int * matrix;
        bool directed;
        bool weighted;
};

#endif // ADJANCYMATRIX_H
