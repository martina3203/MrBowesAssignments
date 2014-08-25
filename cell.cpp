#include "cell.h"

cell::cell()
{
    //Constructor
    currentState = dead;
    topLeftPointer = NULL;
    topCenterPointer = NULL;
    topRightPointer = NULL;
    leftCenterPointer = NULL;
    rightCenterPointer = NULL;
    bottomLeftPointer = NULL;
    bottomCenterPointer = NULL;
    bottomRightPointer = NULL;
}

//Makes the cell alive. Only meant for startup
void cell::makeAlive()
{
    currentState = alive;
}

//Toggles cell from being dead or alive
void cell::checkAlive()
{
    //Living cell counter for adjacent cells
    int surroundingLiveCells = 0;

    if ((topLeftPointer != NULL) && ((topLeftPointer -> returnState()) == alive))
    {
        surroundingLiveCells++;
    }
    if ((topCenterPointer != NULL) && ((topCenterPointer -> returnState() == alive)))
    {
        surroundingLiveCells++;
    }
    if ((topRightPointer != NULL) && ((topRightPointer -> returnState()) == alive))
    {
        surroundingLiveCells++;
    }
    if ((leftCenterPointer != NULL) && ((leftCenterPointer -> returnState()) == alive))
    {
        surroundingLiveCells++;
    }
    if ((rightCenterPointer != NULL) && ((rightCenterPointer -> returnState()) == alive))
    {
        surroundingLiveCells++;
    }
    if ((bottomLeftPointer != NULL) && ((bottomLeftPointer -> returnState()) == alive))
    {
        surroundingLiveCells++;
    }
    if ((bottomCenterPointer != NULL) && ((bottomCenterPointer -> returnState()) == alive))
    {
        surroundingLiveCells++;
    }
    if ((bottomRightPointer != NULL) && (bottomRightPointer -> returnState()) == alive)
    {
        surroundingLiveCells++;
    }

    //std::cout << surroundingLiveCells;

    //Check the rules of being an alive cell
    if ((surroundingLiveCells == 2) || (surroundingLiveCells == 3))
    {
        //If there is 2 or 3 neighbors, there are alive.
        currentState = alive;
    }
    else
    {
        //If there is more than 3, there are dead.
        currentState = dead;
    }
    return;
}

//Sets Cell X Coordinate
void cell::setX(int x)
{
    xCoordinate = x;
}

//Sets Cell Y Coordinate
void cell::setY(int y)
{
    yCoordinate = y;
}

//Return X Value
int cell::returnX()
{
    return xCoordinate;
}

//Return Y Value
int cell::returnY()
{
    return yCoordinate;
}

//Return cell's current state
cellState cell::returnState()
{
    return currentState;
}

//Test functionality
void cell::testCell()
{
    cell * newCell = new cell;
    cell * secondCell = new cell;
    cell * thirdCell = new cell;
    cell * fourthCell = new cell;
    cell * fifthCell = new cell;
    cell * sixthCell = new cell;

    //Modify cells as needed to test it
    setX(5);
    setY(5);
    newCell -> setX(6);
    newCell -> setY(4);
    newCell -> makeAlive();
    secondCell -> setX(5);
    secondCell -> setY(4);
    secondCell -> makeAlive();
    thirdCell -> setX(4);
    thirdCell -> setY(4);
    thirdCell -> makeAlive();
    fourthCell -> setX(4);
    fourthCell -> setY(5);
    fourthCell -> makeAlive();
    fifthCell -> setX(5);
    fifthCell -> setY(6);
    fifthCell -> makeAlive();
    sixthCell -> setX(5);
    sixthCell -> setY(6);
    sixthCell -> makeAlive();

    std::vector<cell*> testVector;
    testVector.push_back(newCell);
    testVector.push_back(secondCell);
    testVector.push_back(thirdCell);
    testVector.push_back(fourthCell);
    testVector.push_back(fifthCell);
    testVector.push_back(sixthCell);

    connectCells(testVector);
    std::cout << topLeftPointer -> returnX() << "," << topLeftPointer -> returnY();
    //std::cout << topRightPointer -> returnX() << "," << topRightPointer -> returnY();
    //std::cout << topCenterPointer -> returnX() << "," << topCenterPointer -> returnY();
    //std::cout << leftCenterPointer -> returnX() << "," << leftCenterPointer -> returnY();
    //std::cout << rightCenterPointer -> returnX() << "," << rightCenterPointer -> returnY();
    std::cout << bottomCenterPointer -> returnX() << "," << bottomCenterPointer -> returnY();
    //checkAlive();
    if (returnState() == alive)
    {
        std::cout << "I am alive" << std::endl;
    }
    else
    {
        std::cout << "I am dead" << std::endl;
    }

    delete newCell;
    newCell = NULL;
    delete secondCell;
    secondCell = NULL;
    delete thirdCell;
    thirdCell = NULL;
    delete fourthCell;
    fourthCell = NULL;
    delete fifthCell;
    fifthCell = NULL;
    delete sixthCell;
    sixthCell = NULL;
}

void cell::connectCells(std::vector<cell*> &cellList)
{
    for (int i = 0; i < cellList.size(); i++)
    {
        cell * currentViewedCell;
        currentViewedCell = cellList[i];
        int currentX = currentViewedCell -> returnX();
        int currentY = currentViewedCell -> returnY();

        //Compares the locations of different pointers to see where they correlate to current pointers
        //Top Left Comparison
        if ((currentX+1 == xCoordinate) && (currentY+1 == yCoordinate))
        {
            //std::cout << "Connect Top Left" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            topLeftPointer = currentViewedCell;
        }
        //Top Center Comparison
        else if ((currentX == xCoordinate) && (currentY+1 == yCoordinate))
        {
            //std::cout << "Connect Top Center" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            topCenterPointer = currentViewedCell;
        }

        //Top Right Comparison
        else if ((currentX-1 == xCoordinate) && (currentY+1 == yCoordinate))
        {
            //std::cout << "Connect Top Right" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            topRightPointer = currentViewedCell;
        }

        //Center Left Comparison
        else if ((currentX+1 == xCoordinate) && (currentY == yCoordinate))
        {
            //std::cout << "Connect Center Left" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            leftCenterPointer = currentViewedCell;
        }

        //Center Right Comparison
        else if ((currentX-1 == xCoordinate) && (currentY == yCoordinate))
        {
            //std::cout << "Connect Center Right" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            rightCenterPointer = currentViewedCell;
        }
        //Lower Left Comparison
        else if ((currentX+1 == xCoordinate) && (currentY-1 == yCoordinate))
        {
            //std::cout << "Connect Lower Left" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            bottomLeftPointer = currentViewedCell;
        }
        //Lower Center Comparison
        else if ((currentX == xCoordinate) && (currentY-1 == yCoordinate))
        {
            //std::cout << "Connect Lower Center" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            bottomCenterPointer = currentViewedCell;
        }
        //Lower Right Comparison
        else if ((currentX-1 == xCoordinate) && (currentY-1 == yCoordinate))
        {
            //std::cout << "Connect Lower Right" << currentX << "," << currentY << " to " << xCoordinate << "," << yCoordinate << std::endl;
            bottomRightPointer = currentViewedCell;
        }
        else
        {
            //Do nothing
        }
    }
}

cell * cell::returnAdjacentCell(int numberCode)
{
    if (numberCode == 1)
    {
        return topLeftPointer;
    }
    else if (numberCode == 2)
    {
        return topCenterPointer;
    }
    else if (numberCode == 3)
    {
        return topRightPointer;
    }
    else if (numberCode == 4)
    {
        return leftCenterPointer;
    }
    else if (numberCode == 6)
    {
        return rightCenterPointer;
    }
    else if (numberCode == 7)
    {
        return bottomLeftPointer;
    }
    else if (numberCode == 8)
    {
        return bottomCenterPointer;
    }
    else if (numberCode == 9)
    {
        return bottomRightPointer;
    }
    else
    {
        std::cout << "Error: invalid code" << std::endl;
        return NULL;
    }
}

cell::~cell()
{
    //Destructor
}
