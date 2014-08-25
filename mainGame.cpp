#include "gameClass.h"

int main()
{
    gameClass Life;
    std::cout << "Select Mode for Usage:" << std::endl << "1. Random" << std::endl;
    int keyNumber = 1;
    std::cin >> keyNumber;
    Life.startGame(keyNumber);
    cell testCell;
    testCell.testCell();

    return 1;
}
