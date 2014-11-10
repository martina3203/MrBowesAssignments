#include "adjancyMatrix.h"
#include "adjancyList.h"

int main()
{
    /*
    adjancyMatrix newGraph;
    newGraph.addVertex("Poop");
    newGraph.addVertex("Chicken");
    newGraph.addVertex("Waka");
    //newGraph.depthFirst("Poop");
    newGraph.printVertices();
    newGraph.breadthFirst("Chicken");
    */
    adjancyList otherGraph;
    otherGraph.addVertex("New");
    otherGraph.addVertex("Sara");
    otherGraph.addVertex("Alex");
    otherGraph.breadthFirst("Sara");
    //otherGraph.removeVertex("New");
    //otherGraph.depthFirst("Alex");
    return 1;
}
