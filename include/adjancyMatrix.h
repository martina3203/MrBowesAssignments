#ifndef ADJANCYMATRIX_H
#define ADJANCYMATRIX_H

#include "vertex.h"

class adjancyMatrix
{
    public:
        adjancyMatrix();
        virtual ~adjancyMatrix();
        void addVertex(std::string,std::vector<std::string>);
        void removeVertex(std::string target);
        void printVertices();
    protected:
    private:
        void rebuildMatrix();
        std::vector<vertex*> verticeList;
        int matrix;
};

#endif // ADJANCYMATRIX_H
