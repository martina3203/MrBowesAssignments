#include "gameClass.h"
#include <stdlib.h>

gameClass::gameClass()
{
    //Set Window Attributes to Null
    gameWindow = NULL;
    infoWindow = NULL;

    //Set Counter Attributes
    generationNumber = 0;
    aliveCellCount = 0;
}

gameClass::~gameClass()
{
    //Destructor
    //Clears window pointers, if they were used
    if (gameWindow != NULL)
    {
        delete gameWindow;
        delete infoWindow;
        gameWindow = NULL;
        infoWindow = NULL;
    }

    //Clears cell pointers, if they were used
    if (cellList.empty() != true)
    {
        for (unsigned int i = 0; i < (GAME_WINDOW_HEIGHT * GAME_WINDOW_WIDTH); i++)
        {
            cell * cellPointer = cellList[i];
            delete cellPointer;
            cellPointer = NULL;
        }
    }
}

void gameClass::startGame(int numberCode)
{
    int userNumber;
    std::cout << "Please select the number of cells to start with" << std::endl;
    std::cin >> userNumber;
    createCells();
    srand(time(NULL));

    for (unsigned int i = 0; i < userNumber; i++)
    {
        int randomX = rand() % GAME_WINDOW_WIDTH;
        int randomY = rand() % GAME_WINDOW_HEIGHT;
        cell * currentCell;
        if (numberCode == 1)
        {
            for (unsigned int h = 0; h < cellList.size(); h++)
            {
                currentCell = cellList.at(h);
                if (((currentCell -> returnX()) == randomX) && ((currentCell -> returnY()) == randomY))
                {
                    currentCell -> makeAlive();
                }
            }
        }
    }

    calculateCount();
    sortAlive();
    while(1)
    {
        updateCells();
    }

}

void gameClass::updateCells()
{
    //Checks the status of the current cells
    for (unsigned int i = 0; i < cellList.size(); i++)
    {
        if (cellList.at(i) -> returnState() == alive)
        {
            for (unsigned int h = 1; h < 10; h++)
            {
                if (h != 5)
                {
                    cell * targetCell = cellList.at(i) -> returnAdjacentCell(h);
                    if (targetCell != NULL)
                    {
                        targetCell -> checkAlive();
                        targetCell -> makeChange();
                        drawWindow();

                    }
                }
            }
            _sleep(1);
            cellList.at(i) -> checkAlive();
            cellList.at(i) -> makeChange();
        }
    }
    sortAlive();
    calculateCount();
    return;
}

//Counts up the number of cells that are alive and updates generation count
void gameClass::calculateCount()
{
    generationNumber = generationNumber++;
    aliveCellCount = 0;
    for (unsigned int i = 0; i < cellList.size(); i++)
    {
        if ((cellList.at(i) -> returnState()) == alive)
        {
            aliveCellCount = aliveCellCount++;
        }
    }
    return;
}

//Updates the window accordingly
void gameClass::drawWindow()
{
    //Clears anything that might be on the window now
    wclear(gameWindow);
    wclear(infoWindow);

    if ((gameWindow == NULL) && (infoWindow == NULL))
    {
        //Sets up Window
        initscr();
        curs_set(0);
        noecho();

        //Sets up color code
        start_color();
        init_pair(1,COLOR_BLACK,COLOR_GREEN);
        init_pair(2,COLOR_WHITE,COLOR_BLACK);

        gameWindow = newwin(GAME_WINDOW_HEIGHT,GAME_WINDOW_WIDTH,0,0);
        infoWindow = newwin(INFO_WINDOW_HEIGHT,INFO_WINDOW_WIDTH,0,60);

        wbkgd(gameWindow,COLOR_PAIR(1));
        wbkgd(infoWindow,COLOR_PAIR(2));
    }

    //Prints all alive cells on the map
    for (unsigned int i = 0; i < cellList.size(); i++)
    {
        if (cellList.at(i) -> returnState() == alive)
        {
            if (((cellList.at(i) -> returnX() >= 0) && (cellList.at(i) -> returnX() <= GAME_WINDOW_WIDTH)) &&
                ((cellList.at(i) -> returnY() >= 0) && cellList.at(i) -> returnY() <= GAME_WINDOW_HEIGHT))
                {
                    mvwaddch(gameWindow,cellList.at(i)->returnY(),cellList.at(i)->returnX(),'A');
                }
        }
    }

    //Information Window material
    //Set up a char pointer so that you can pass in strings to be printed
    //Printing Generation Number
    std::string phrase = "Generation #:";
    char * phrasePointer = &phrase.at(0);
    mvwprintw(infoWindow,0,0,phrasePointer);
    mvwprintw(infoWindow,1,0,"%d",generationNumber);

    //Printing Number of Living Cells
    phrase = "Living Cell Count:";
    phrasePointer = &phrase.at(0);
    mvwprintw(infoWindow,3,0,phrasePointer);
    mvwprintw(infoWindow,4,0,"%d",aliveCellCount);


    refresh();
    wrefresh(gameWindow);
    wrefresh(infoWindow);

    return;
}

//Creates intial cells
void gameClass::createCells()
{
    //Create enough cells to fill the current game window settings
    for (int i = 0; i < (GAME_WINDOW_HEIGHT+10); i++)
    {
        for (int h = 0; h < (GAME_WINDOW_WIDTH+10); h++)
        {
            //Create cell
            cell * cellPointer = new cell;
            //Give the cell coordinates
            cellPointer -> setX(h);
            cellPointer -> setY(i);
            //Add to list for removal later
            cellList.push_back(cellPointer);
        }
    }

    //Link all the cells together
    for (unsigned int i = 0; i < cellList.size(); i++)
    {
        cellList.at(i) -> connectCells(cellList);
    }
    return;
}

void gameClass::sortAlive()
{
    std::vector<cell*> newList;
    //Sorts alive cells to front
    for (unsigned int i = 0; i < cellList.size(); i++)
    {
        if (cellList.at(i) -> returnState() == alive)
        {
            newList.push_back(cellList.at(i));
        }
    }
    //Then adds dead cells to back of list
    for (unsigned int i = 0; i < cellList.size(); i++)
    {
        if (cellList.at(i) -> returnState() == dead)
        {
            newList.push_back(cellList.at(i));
        }
    }
    //Copies over new list
    cellList = newList;
    return;
}

void wait(int sec) //credit to http://www.cplusplus.com/forum/beginner/74239/
{
    clock_t endwait;
    endwait = clock() + sec * CLK_TCK;
    while (clock() < endwait) {}
    return;
}
