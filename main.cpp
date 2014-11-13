#include "adjancyMatrix.h"
#include "adjancyList.h"

int main()
{
    adjancyList newList;
    newList.addVertex("Poop");
    newList.addVertex("Chicken");
    newList.addVertex("Sara");
    newList.removeVertex("Poop");
    newList.printList();
    return 1;
}
