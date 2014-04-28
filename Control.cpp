#include "Control.h"


Control::Control()
{
    //Constructor
    //Establish Windows and set everything else to nothing
    gameWindow = NULL;
    information = NULL;
    mapName = "";
    randomNumberSeed = 0;
    totalSimulationRuns = 0;
    currentRunNumber = 1;
    deathByStarvation = 0;
    deathByCat = 0;
    deathByDrowning = 0;

    //Seed random number generator
    randomNumberSeed = time(NULL);
    srand(time(NULL));

    //Fills Arrays with no significant characters
    for (int i = 0; i < 20; i++)
    {
        for (int h = 0; h < 20; h++)
        {
            mapArray[i][h] = 'N';
            savedMap[i][h] = 'N';
        }
    }
}

//The Actual Program
void Control::runSimulation()
{
    readFile();
    while (currentRunNumber <= totalSimulationRuns)
    {
        trialRun();
        printScreen();
    }
    writeToFile();
    return;
}

void Control::trialRun()
{
    char mouseStatus = ' ';
    printScreen();
    wait(1);
    while ((mouseStatus != 'V') && (mouseStatus != 'D') && (mouseStatus != 'C') && (mouseStatus != 'S'))
    {
        catMove();
        mouseStatus = mouseMove();
        printScreen();
        wait(1);
    }
    updateData(mouseStatus);
    reloadMap();
    return;
}

void Control::catMove()
{
    //Select Number 1 through 3
    bool validMove = false;
    int lastCatX = theCat.returnXCoordinate();
    int lastCatY = theCat.returnYCoordinate();

    while (validMove == false)
    {
        int selection = rand() % 4;
        switch(selection)
        {
            //Up
            case 0:
                //if (mapArray[catX][catY])
                theCat.unitMove(selection);
                break;
            //Down
            case 1:
                theCat.unitMove(selection);
                break;
            //Left
            case 2:
                theCat.unitMove(selection);
                break;
            //Right
            case 3:
                theCat.unitMove(selection);
                break;
            default:
                std::cout << "You messed up the cat, A-A-Ron";
                break;
        }

         if (mapArray[theCat.returnXCoordinate()][theCat.returnYCoordinate()] == '~')
         {
            //Restart loop until it gets a valid position
            theCat.setXCoordinate(lastCatX);
            theCat.setYCoordinate(lastCatY);
            validMove = false;
         }
         else
         {
             validMove = true;
         }
    }

}

char Control::mouseMove()
{
    //Select Number 0 through 3
    int selection = rand() % 4;
    switch(selection)
    {
        //Up
        case 0:
            theMouse.unitMove(selection);
            break;
        //Down
        case 1:
            theMouse.unitMove(selection);
            break;
        //Left
        case 2:
            theMouse.unitMove(selection);
            break;
        //Right
        case 3:
            theMouse.unitMove(selection);
            break;
        default:
            std::cout << "You messed up, A-A-Ron";
            break;
    }

    theMouse.decrementFoodCount();

    //Acquire current positions of specimens
    int mouseX = theMouse.returnXCoordinate();
    int mouseY = theMouse.returnYCoordinate();
    int catX = theCat.returnXCoordinate();
    int catY = theCat.returnYCoordinate();


    if (mapArray[mouseY][mouseX] == '~')
    {
        //This signifies he drowned
        return 'D';
    }
    else if (mapArray[mouseY][mouseX] == 'F')
    {
        //He is not starving for another 100 turns
        theMouse.resetFoodCount();
        mapArray[mouseY][mouseX] == ' ';
        return 'F';
    }
    else if (mapArray[mouseY][mouseX] == 'H')
    {
        //The mouse is in a hole
        if (theMouse.getFoodCount() == 0)
        {
            //The Mouse Starved
            return 'S';
        }
        return 'H';
    }
    else if ((mouseX == catX) && (mouseY == catY))
    {
        //The Cat caught him
        return 'C';
    }
    else
    {
        //Found a bridge
        if (mapArray[mouseY][mouseX] == 'B')
        {
            //The Mouse Escaped
            return 'V';
        }

        else if (theMouse.getFoodCount() == 0)
        {
            //The Mouse Starved
            return 'S';
        }

        //Just another open space
        return ' ';
    }

}

void Control::readFile()
{
    bool programStart = false;
    std::string fileName = "";
    std::string mapName = "";
    std::ifstream loadedFile;
    int trials = 0;
    int mapHeight = 0;
    int mapWidth = 0;
    int currentCharacter;

    //Let the user give a valid file name
    while (programStart == false)
    {
        std::cout << "Please designate file name:" << std::endl;
        std::cin >> fileName;
        loadedFile.open(fileName.c_str());          //Open file

        if (loadedFile.is_open())
        {
            programStart = true;
        }
        else
        {
            std::cout << "Please try again. The file is either missing and/or corrupt." << std::endl;             //Failure message
        }
    }
    getline(loadedFile,mapName);
    loadedFile >> trials;
    loadedFile >> mapHeight;
    loadedFile >> mapWidth;

    char confirm = 'a';

    std::cout << std::endl << "The loaded Map is Titled: " << mapName << std::endl;
    std::cout << "The number of Simulation Runs is: " << trials << std::endl;
    std::cout << "The Height of the Map is: " << mapHeight << std::endl;
    std::cout << "The Width of the Map is: " << mapWidth << std::endl << std::endl;
    std::cout << "If this criteria is correct, please press 'Y' then Enter on your keyboard." << std::endl <<
        "If not, please check your file and try the program again." << std::endl << std::endl;
    std::cin >> confirm;
    //Saves information for printing later
    saveInformation(mapName,trials,mapHeight,mapWidth);

    if ((confirm == 'Y') || (confirm == 'y'))
    {
        for (int h = 0; h < mapHeight; h++)
        {
            for (int i = 0; i < mapWidth; i++)
            {
                loadedFile >> currentCharacter;
                if (currentCharacter == 1)
                {
                    //Set up for Mouse
                    theMouse.setXCoordinate(i);
                    theMouse.setYCoordinate(h);
                    mapArray[h][i] = ' ';
                    savedMap[h][i] = 'M';
                }
                else if (currentCharacter == 2)
                {
                    //Set up for Cat
                    theCat.setXCoordinate(i);
                    theCat.setYCoordinate(h);
                    mapArray[h][i] = ' ';
                    savedMap[h][i] = 'C';
                }
                else if (currentCharacter == 3)
                {
                    //Set up for Food
                    mapArray[h][i] = 'F';
                    savedMap[h][i] = 'F';
                }
                else if (currentCharacter == 4)
                {
                    //Set up for Mouse Hole
                    mapArray[h][i] = 'H';
                    savedMap[h][i] = 'H';
                }
                else if (currentCharacter == 0)
                {
                    //If this open space is on the side of the map, make it a bridge
                    if (((h == 0) || (h == mapHeight-1)) || ((i == 0) || (i == mapWidth-1)))
                    {
                        mapArray[h][i] = 'B';
                        savedMap[h][i] = 'B';
                    }
                    else
                    {
                        //Set up for empty space or bridge
                        mapArray[h][i] = ' ';
                        savedMap[h][i] = ' ';
                    }
                }
                else if (currentCharacter < 0)
                {
                    //Set up for Water
                    mapArray[h][i] = '~';
                    savedMap[h][i] = '~';
                }
            }
        }
        return;
    }

    else
    {
        exit(1);                    //Exits the program completely
    }
    return;
}

void Control::reloadMap()
{
    for (int i = 0; i < mapHeight; i++)
    {
        for (int h = 0; h < mapWidth; h++)
        {
            if (savedMap[i][h] == 'M')
            {
                theMouse.setXCoordinate(h);
                theMouse.setYCoordinate(i);
                mapArray[i][h] = ' ';
            }
            else if (savedMap[i][h] == 'C')
            {
                theCat.setXCoordinate(h);
                theCat.setYCoordinate(i);
                mapArray[i][h] = ' ';
            }
            else
            {
                mapArray[i][h] = savedMap[i][h];
            }
        }
    }

    theMouse.resetFoodCount();

    return;
}

void Control::saveInformation(std::string theMap,int numberOfRuns,int height,int width)
{
    //Updates control with map name and total number of runs to go through
    mapName = theMap;
    totalSimulationRuns = numberOfRuns;
    mapHeight = height;
    mapWidth = width;
    return;
}

void Control::printScreen()
{
    //Clears windows so that printing can begin
    wclear(gameWindow);
    wclear(information);
    if (gameWindow == NULL && information == NULL)
    {
        int const GAME_WINDOW_HEIGHT = mapHeight;
        int const GAME_WINDOW_WIDTH = mapWidth;
        int const STATUS_WINDOW_HEIGHT = 15;
        int const STATUS_WINDOW_WIDTH = 35;

        initscr();
        curs_set(0); //set visibility of cursor

        //Creates new window where the game will be played and sets up other options
        gameWindow = newwin(GAME_WINDOW_HEIGHT,GAME_WINDOW_WIDTH,0,0);
        information = newwin(STATUS_WINDOW_HEIGHT,STATUS_WINDOW_WIDTH,0,mapWidth);
        noecho();
        //Color Settings
        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLACK);
        init_pair(2,COLOR_WHITE,COLOR_BLUE);
        init_pair(3,COLOR_WHITE,COLOR_BLACK);
        wbkgd(stdscr, COLOR_PAIR(1));
        wbkgd(gameWindow, COLOR_PAIR(2));
        wbkgd(information, COLOR_PAIR(3));
        cbreak();
        refresh();
    }

    //GAME WINDOW
    int mouseX = theMouse.returnXCoordinate();
    int mouseY = theMouse.returnYCoordinate();
    int catX = theCat.returnXCoordinate();
    int catY = theCat.returnYCoordinate();
    //Prints all the terrain
    for (unsigned int i = 0; i < 20; i++)
    {
        for (unsigned int h = 0; h < 20; h++)
        {
            if (mapArray[i][h] != 'N')
            {
                mvwaddch(gameWindow,i,h,mapArray[i][h]);
            }
            else
            {
                mvwaddch(gameWindow,i,h,ACS_BLOCK);
            }
        }
    }

    //Prints Mouse and Cat
    mvwaddch(gameWindow,mouseY,mouseX,'M');
    mvwaddch(gameWindow,catY,catX,'C');

    //INFORMATION WINDOW
    //Print map name
    std::string printedLine = mapName;
    char * stringPointer = &printedLine.at(0);
    mvwprintw(information,0,1,stringPointer);

    printedLine = "Current Run";
    int printedNumber = currentRunNumber;
    mvwprintw(information,1,1,stringPointer);
    mvwprintw(information,1,14,"%d",printedNumber);

    printedLine = "Total Runs";
    printedNumber = totalSimulationRuns;
    mvwprintw(information,2,1,stringPointer);
    mvwprintw(information,2,14,"%d",printedNumber);

    printedLine = "Food Count";
    printedNumber = theMouse.getFoodCount();
    mvwprintw(information,3,1,stringPointer);
    mvwprintw(information,3,14,"%d",printedNumber);

    printedLine = "Deaths:";
    mvwprintw(information,5,1,stringPointer);

    printedLine = "Cat";
    printedNumber = deathByCat;
    mvwprintw(information,6,1,stringPointer);
    mvwprintw(information,6,14,"%d",printedNumber);

    printedLine = "Starvation";
    printedNumber = deathByStarvation;
    mvwprintw(information,7,1,stringPointer);
    mvwprintw(information,7,14,"%d",printedNumber);

    printedLine = "Drowning";
    printedNumber = deathByDrowning;
    mvwprintw(information,8,1,stringPointer);
    mvwprintw(information,8,14,"%d",printedNumber);

    wrefresh(information);
    wrefresh(gameWindow);

    return;
}

void Control::updateData(char deathCode)
{
    switch(deathCode)
    {
        //Mouse Escaped
        case 'V':
            mouseVictory = mouseVictory++;
            break;
        //Mouse Drowned
        case 'D':
            deathByDrowning = deathByDrowning++;
            break;
        //Mouse got eatne
        case 'C':
            deathByCat = deathByCat++;
            break;
        //Mouse died of hunger
        case 'S':
            deathByStarvation = deathByStarvation++;
            break;
        default:
            std::cout << "You done messed up, A-Aron with codes";
    }
    currentRunNumber = currentRunNumber++;
    return;
}

void Control::writeToFile()
{
    //Writes Output to file
    std::ofstream outputFile;
    std::string outputFileName = "results.txt";
    outputFile.open(outputFileName.c_str());

    outputFile << "Map Name: " << mapName << std::endl;
    outputFile << "Random Number Seed: " << randomNumberSeed << std::endl;
    outputFile << "Total Trial Runs: " << totalSimulationRuns << std::endl;
    outputFile << "Mouse Victories: " << mouseVictory << std::endl;
    outputFile << "Deaths by Water: " << deathByDrowning << std::endl;
    outputFile << "Death by Starvation: " << deathByStarvation << std::endl;
    outputFile << "Death by Cat: " << deathByCat << std::endl;
    return;
}

Control::~Control()
{
    //Destructor
}

void wait(int sec) //credit to http://www.cplusplus.com/forum/beginner/74239/
{
    clock_t endwait;
    endwait = clock() + sec * CLK_TCK;
    while (clock() < endwait) {}
    return;
}


