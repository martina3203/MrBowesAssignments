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
    otherGraph.removeVertex("New");
    otherGraph.printList();
    return 1;
}
