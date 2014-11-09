#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>

class vertex
{
    public:
        vertex();
        virtual ~vertex();
        void setName(std::string);
        std::string returnName();
        void addToAdjacentList(vertex*);
        std::vector<vertex*> returnAdjacentList();
        void clearList();
        bool wasVisited();
        void setVisitFlag(bool);
    private:
        std::string vertexName; //Vertex name
        std::vector<vertex*> adjacentList;
        bool visited;
        int X;  //X Coordinate
        int Y;  //Y Coordinate

};

#endif // VERTEX_H
