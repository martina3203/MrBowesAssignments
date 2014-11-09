#include "adjancyMatrix.h"

int main()
{
    adjancyMatrix newGraph;
    newGraph.addVertex("Poop");
    newGraph.addVertex("Chicken");
    newGraph.addVertex("Waka");
    newGraph.printVertices();
    newGraph.removeVertex("Poop");
    newGraph.printVertices();
    return 1;
}
