#ifndef UNITS_H
#define UNITS_H

class Unit
{
public:
    Unit();
    void unitMove(int direction);
    void setXCoordinate(int X);
    void setYCoordinate(int Y);
    int returnXCoordinate();
    int returnYCoordinate();
    ~Unit();

private:
    int xCoordinate;
    int yCoordinate;
};


class Mouse: public Unit
{
public:
    Mouse();
    ~Mouse();
    void resetFoodCount();
    int getFoodCount();
    void decrementFoodCount();

private:
    int foodCount;
};

#endif // UNITS_H
