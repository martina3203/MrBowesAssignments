#ifndef GAMECLASS_H
#define GAMECLASS_H

#include <curses.h>
#include "cell.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class gameClass
{
public:
    gameClass();
    ~gameClass();
    void drawWindow();
    void createCells();
    void startGame(int numberCode);
    void updateCells();
    void calculateCount();
    void testWindow();

private:
    //Window Attributes
    WINDOW * gameWindow;
    WINDOW * infoWindow;
    unsigned int GAME_WINDOW_HEIGHT = 23;
    unsigned int GAME_WINDOW_WIDTH = 59;
    unsigned int INFO_WINDOW_HEIGHT = 23;
    unsigned int INFO_WINDOW_WIDTH = 19;

    //Cell List
    std::vector<cell*> cellList;

    //Counters
    unsigned int generationNumber;
    unsigned int aliveCellCount;
};

void wait(int sec);

#endif // GAMECLASS_H
