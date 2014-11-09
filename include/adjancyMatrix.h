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
        void removeVertex(std::string targetVertex);
        void printVertices();
    protected:
    private:
        void rebuildMatrix();
        std::vector<vertex*> verticeList;
        int * matrix;
        bool directed;
        bool weighted;
};

#endif // ADJANCYMATRIX_H
