#include "adjancyMatrix.h"
#include "adjancyList.h"

int main()
{
    adjancyList newList;
    newList.addVertex("B");
    newList.addVertex("A");
    newList.addVertex("C");
    newList.addVertex("D");
    newList.Dijkstra("B","D");
    return 1;
}
