#include "Units.h"

Unit::Unit()
{
    //Constructor
}


void Unit::unitMove(int direction)
{
    switch(direction)
    {
        //Up
        case 0:
            yCoordinate--;
            break;
        //Down
        case 1:
            yCoordinate++;
            break;
        //Left
        case 2:
            xCoordinate--;
            break;
        //Right
        case 3:
            xCoordinate++;
            break;
        default:
            break;
    };

    return;
}


void Unit::setXCoordinate(int X)
{
    xCoordinate = X;
    return;
}

void Unit::setYCoordinate(int Y)
{
    yCoordinate = Y;
    return;
}

int Unit::returnXCoordinate()
{
    return xCoordinate;
}

int Unit::returnYCoordinate()
{
    return yCoordinate;
}

Unit::~Unit()
{
    //Destructor
}

Mouse::Mouse()
{
    //Cosntructor
    foodCount = 100;
}

void Mouse::resetFoodCount()
{
    //Resets count to 100
    foodCount = 100;
    return;
}

int Mouse::getFoodCount()
{
    //Returns current food count
    return foodCount;
}

void Mouse::decrementFoodCount()
{
    //Decrements food count
    foodCount = foodCount - 1;
    return;
}
Mouse::~Mouse()
{
    //Destructor
}
