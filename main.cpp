#include "adjancyMatrix.h"

int main()
{

    adjancyMatrix newGraph;
    newGraph.addVertex("Poop");
    newGraph.addVertex("Chicken");
    newGraph.addVertex("Waka");
    newGraph.removeVertex("Poop");
    //newGraph.depthFirst("Poop");
    newGraph.printVertices();
    //newGraph.breadthFirst("Chicken");

    return 1;
}
