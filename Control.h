#ifndef CONTROL_H
#define CONTROL_H

#include <curses.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <istream>
#include <fstream>
#include <string>
#include <ctime>
#include "Units.h"
#include "VectorArrayFunctions.cpp"

class Control
{
public:
    Control();
    void readFile();
    void reloadMap();
    void runSimulation();
    void trialRun();
    void printScreen();
    void updateData(char deathCode);
    void writeToFile();
    void catMove();
    char mouseMove();
    void saveInformation(std::string theMap, int numberOfRuns,int height,int width);
    void terminateProgram();
    ~Control();

private:
    Mouse theMouse;
    Unit theCat;
    WINDOW * gameWindow;
    WINDOW * information;
    char mapArray[20][20];
    char savedMap[20][20];
    std::string mapName;
    int randomNumberSeed;
    int mapWidth;
    int mapHeight;
    int totalSimulationRuns;
    int currentRunNumber;
    int deathByStarvation;
    int deathByCat;
    int deathByDrowning;
    int mouseVictory;
};


void wait(int sec); //credit to http://www.cplusplus.com/forum/beginner/74239/
#endif // CONTROL_H
