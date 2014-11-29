#include "adjancyMatrix.h"
#include "adjancyList.h"

int main()
{
    adjancyList newList;
    adjancyMatrix newMatrix;
    bool ifMatrix = true;
    int input = 0;
    std::string newName;
    std::string endPoint;
    std::cout << "Please press 1 for Adjancy List, 2 for Matrix" << std::endl;
    std::cin >> input;
    if (input == 1)
    {
        ifMatrix = false;
    }
    else if (input == 2)
    {
        ifMatrix = true;
    }
    else
    {
        std::cout << "Invalid input. Exiting" << std::endl;
        return input;
    }
    while (input != 0)
    {
        std::cout << "Press 1 to add a Vertex, 2 to remove, 3 for Dijkstra's, 4 for Prim's and 5 for Kruskal's" << std::endl;
        std::cout << "Press 0 to quit" << std::endl;
        std::cin >> input;
        switch(input)
        {
            case 0:
                std::cout << "Exiting" << std::endl;
                break;
            case 1:
                std::cout << "Vertex Name:" << std::endl;
                std::cin >> newName;
                if (ifMatrix == true)
                {
                    newMatrix.addVertex(newName);
                }
                else
                {
                    newList.addVertex(newName);
                }
                break;
            case 2:
                std::cout << "Vertex Name to Remove:" << std::endl;
                std::cin >> newName;
                if (ifMatrix == true)
                {
                    newMatrix.removeVertex(newName);
                }
                else
                {
                    newList.removeVertex(newName);
                }
                break;
            case 3:
                std::cout << "List starting vertex: " << std::endl;
                std::cin >> newName;
                std::cout << "Now the end point: ";
                std::cin >> endPoint;
                if (ifMatrix == true)
                {
                    newMatrix.Dijkstra(newName);
                    newMatrix.findPath(newName,endPoint);
                }
                else
                {
                    newList.Dijkstra(newName);
                    newList.findPath(newName,endPoint);
                }
                break;
            case 4:
                std::cout << "List starting vertex: " << std::endl;
                std::cin >> newName;
                if (ifMatrix == true)
                {
                    newMatrix.Prim(newName);
                }
                else
                {
                    newList.Prim(newName);
                }
                break;
            case 5:
                if (ifMatrix == true)
                {
                    newMatrix.Kruskal();
                }
                else
                {
                    newList.Kruskal();
                }
                break;
            default:
                std::cout << "Invalid input. Try again." << std::endl;

        }
    }
    /*
    adjancyList newList;
    newList.addVertex("B");
    newList.addVertex("A");
    newList.addVertex("C");
    newList.addVertex("D");
    newList.Prim("B");
    newList.findPath("B","D");
    return 1;
    */
}
