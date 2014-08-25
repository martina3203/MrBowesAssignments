#ifndef CELL_H
#define CELL_H


#include <vector>
#include <iostream>


enum cellState
{
    dead,
    alive
};

class cell
{
public:
    cell();
    void makeAlive();
    void checkAlive();
    void setX(int x);
    void setY(int y);
    int returnX();
    int returnY();
    cellState returnState();
    cell * returnAdjacentCell(int numberCode);
    void connectCells(std::vector<cell*> &cellList);
    void testCell();
    ~cell();
private:
    int xCoordinate;
    int yCoordinate;
    cellState currentState;

    cell * topLeftPointer;
    cell * topCenterPointer;
    cell * topRightPointer;
    cell * leftCenterPointer;
    cell * rightCenterPointer;
    cell * bottomLeftPointer;
    cell * bottomCenterPointer;
    cell * bottomRightPointer;
};


#endif // CELL_H
