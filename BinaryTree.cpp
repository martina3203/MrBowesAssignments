#include "BinaryTree.h"
#include "AVLTree.h"

int main()
{
    AVLTree newTree;
    newTree.interface();
}






node::node()
{
    data = 0;
    leftPointer = NULL;
    rightPointer = NULL;
}

node::~node()
{

}

int node::returnData()
{
    return data;
}

node * node::returnLeftPointer()
{
    return leftPointer;
}

node * node::returnRightPointer()
{
    return rightPointer;
}

void node::setData(int newData)
{
    data = newData;
}

void node::setLeftPointer(node * newPointer)
{
    leftPointer = newPointer;
}

void node::setRightPointer(node * newPointer)
{
    rightPointer = newPointer;
}





BinaryTree::BinaryTree()
{
    headNode = NULL;
}

BinaryTree::~BinaryTree()
{
    if (headNode != NULL)
    {
        deleteNode(headNode);
    }
}

void BinaryTree::addToTree(int newData)
{
    node * newNode;
    if (headNode == NULL)
    {
        std::cout << "Node Established" << std::endl;
        headNode = new node;
        headNode -> setData(newData);
        headNode -> setLeftPointer(NULL);
        headNode -> setRightPointer(NULL);
    }
    else
    {
        addToBranches(headNode, newData);
    }
}

void BinaryTree::addToBranches(node * newPointer, int newData)
{
    int currentData = newPointer -> returnData();
    node * newNode;
    if (newData < currentData)
    {
        if (newPointer -> returnLeftPointer() == NULL)
        {
            newNode = new node;
            newPointer -> setLeftPointer(newNode);
            newNode -> setData(newData);
            newNode -> setLeftPointer(NULL);
            newNode -> setRightPointer(NULL);
        }
        else
        {
            addToBranches((newPointer -> returnLeftPointer()), newData);
        }
    }
    else if (newData > currentData)
    {
        if (newPointer -> returnRightPointer() == NULL)
        {
            newNode = new node;
            newPointer -> setRightPointer(newNode);
            newNode -> setData(newData);
            newNode -> setLeftPointer(NULL);
            newNode -> setRightPointer(NULL);
        }
        else
        {
            addToBranches((newPointer -> returnRightPointer()), newData);
        }
    }
    else
    {
        std::cout << "This node already exists." << std::endl;
    }
}

void BinaryTree::deleteNode(node* thePointer)
{
    if (thePointer -> returnLeftPointer() != NULL)
    {
        deleteNode(thePointer -> returnLeftPointer());
    }
    if (thePointer -> returnRightPointer() != NULL)
    {
        deleteNode(thePointer -> returnRightPointer());
    }
    delete thePointer;
    thePointer = NULL;
}

void BinaryTree::printTree(int theCode)
{
    if (headNode == NULL)
    {
        std::cout << "List is Empty" << std::endl;
        return;
    }

    //In-Order
    if (theCode == 1)
    {
        if (headNode -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,headNode-> returnLeftPointer());
        }
        std::cout << headNode -> returnData() << std::endl;
        if (headNode -> returnRightPointer() != NULL)
        {
            printBranch(theCode,headNode -> returnRightPointer());
        }
    }
    //Pre-Order
    else if (theCode == 2)
    {
        std::cout << headNode -> returnData() << std::endl;
        if (headNode -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,headNode-> returnLeftPointer());
        }
        if (headNode -> returnRightPointer() != NULL)
        {
            printBranch(theCode,headNode -> returnRightPointer());
        }
    }
    //Post-Order
    else if (theCode == 3)
    {
        if (headNode -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,headNode-> returnLeftPointer());
        }
        if (headNode -> returnRightPointer() != NULL)
        {
            printBranch(theCode,headNode -> returnRightPointer());
        }
        std::cout << headNode -> returnData() << std::endl;
    }
    //Groot-Order
    else
    {
        if (headNode -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,headNode-> returnLeftPointer());
        }
        if (headNode -> returnRightPointer() != NULL)
        {
            printBranch(theCode,headNode -> returnRightPointer());
        }
        std::cout << "We are Groot" << std::endl;
    }
}

void BinaryTree::printBranch(int theCode, node * thePointer)
{
    //In-Order
    if (theCode == 1)
    {
        if (thePointer -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,thePointer-> returnLeftPointer());
        }
        std::cout << thePointer -> returnData() << std::endl;
        if (thePointer -> returnRightPointer() != NULL)
        {
            printBranch(theCode,thePointer -> returnRightPointer());
        }
    }
    //Pre-Order
    else if (theCode == 2)
    {
        std::cout << thePointer -> returnData() << std::endl;
        if (thePointer -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,thePointer-> returnLeftPointer());
        }
        if (thePointer -> returnRightPointer() != NULL)
        {
            printBranch(theCode,thePointer -> returnRightPointer());
        }
    }
    //Post-Order
    else if (theCode == 3)
    {
        if (thePointer -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,thePointer-> returnLeftPointer());
        }
        if (thePointer -> returnRightPointer() != NULL)
        {
            printBranch(theCode,thePointer -> returnRightPointer());
        }
        std::cout << thePointer -> returnData() << std::endl;
    }
    //Groot-Order
    else
    {
        if (thePointer -> returnLeftPointer() != NULL)
        {
            printBranch(theCode,thePointer-> returnLeftPointer());
        }
        if (thePointer -> returnRightPointer() != NULL)
        {
            printBranch(theCode,thePointer -> returnRightPointer());
        }
        std::cout << "I Am Groot" << std::endl;
    }
}
