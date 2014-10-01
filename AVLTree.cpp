#include "AVLTree.h"

AVLTree::AVLTree()
{
    //ctor
}

AVLTree::~AVLTree()
{
    //dtor
}

node * AVLTree::rightRotate(node * thePointer)
{
    node * temp = thePointer -> returnLeftPointer();
    if (temp != NULL)
    {
        thePointer -> setLeftPointer(temp -> returnRightPointer());
        temp -> setRightPointer(thePointer);
        return temp;
    }
    return thePointer;
}

node * AVLTree::leftRotate(node * thePointer)
{
    //Set Temp equal to the Right Pointer
    node * temp = thePointer -> returnRightPointer();
    if (temp != NULL)
    {
        //Right Pointer becomes the left pointer the Pointer's right child.
        thePointer -> setRightPointer(temp -> returnLeftPointer());
        //The previous right pointer becomes the the left pointer of the right child's
        temp -> setLeftPointer(thePointer);
        return temp;
    }
    return thePointer;
}

void AVLTree::addToTree(int newData)
{
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
        checkBalance(headNode);
    }
}

int AVLTree::returnHeight(node * thePointer)
{
    int height = 0;
    if (thePointer != NULL)
    {
        int leftHeight = returnHeight(thePointer -> returnLeftPointer());
        int rightHeight = returnHeight(thePointer -> returnRightPointer());
        if (leftHeight < rightHeight)
        {
            return rightHeight + 1;
        }
        else
        {
            return leftHeight + 1;
        }
    }
    return height;
}


int AVLTree::checkBalance(node * thePointer)
{
    int leftValue = 0;
    int rightValue = 0;
    int returnValue;
    if (thePointer != NULL)
    {
        //Checks left value
        if (thePointer -> returnLeftPointer() != NULL)
        {
            leftValue = returnHeight(thePointer -> returnLeftPointer());
        }
        //Checks right value
        if (thePointer -> returnRightPointer() != NULL)
        {
            rightValue = returnHeight(thePointer -> returnRightPointer());
        }

        //Find difference in heights
        returnValue = leftValue - rightValue;

        if (returnValue == 2)
        {
            if (checkBalance(thePointer -> returnRightPointer()) == -1)
            {
                std::cout << "Perform Double Right" << std::endl;
                thePointer -> setRightPointer(leftRotate(thePointer->returnRightPointer()));
            }
            std::cout << "Right Rotation" << std::endl;
            if (thePointer == headNode)
            {
                headNode = rightRotate(thePointer);
            }
        }
        else if (returnValue == -2)
        {
            if (checkBalance(thePointer -> returnLeftPointer()) == 1)
            {
                std::cout << "Perform Double Left" << std::endl;
                thePointer = rightRotate(thePointer);
            }
            std::cout << "Left Rotation" << std::endl;
            if (thePointer == headNode)
            {
                headNode = leftRotate(thePointer);
            }
        }
        return returnValue;
    }
    else
    {
        return 0;
    }
}

int AVLTree::deleteNode(int target, node * thePointer)
{
    if (thePointer != NULL)
    {
        node * currentNode = thePointer;
        int depth = 0;
        if (currentNode -> returnData() == target)
        {
            node * savedNode = currentNode;
            currentNode = findSmallestNode(headNode,depth);
            if (currentNode != NULL)
            {
                std::cout << "Found " << currentNode -> returnData() << std::endl;
                savedNode -> setData(currentNode -> returnData());
                delete currentNode;
                currentNode = NULL;
                //checkBalance(headNode);
                return target;
            }
        }
        else if (currentNode -> returnData() < target)
        {
            return deleteNode(target,currentNode -> returnRightPointer());
        }
        else if (currentNode -> returnData() > target)
        {
            return deleteNode(target, currentNode -> returnLeftPointer());
        }
        else
        {
            std::cout << "Node does not exist" << std::endl;
        }
    }
    return 0;
}

node * AVLTree::findSmallestNode(node * thePointer, int &depth)
{
    node * leftComparisonNode = NULL;
    node * rightComparisonNode = NULL;
    int leftDepth = depth;
    int rightDepth = depth;
    if (thePointer -> returnLeftPointer() != NULL)
    {
        leftDepth = leftDepth + 1;
        leftComparisonNode = findSmallestNode(thePointer -> returnLeftPointer(),leftDepth);
    }
    if (thePointer -> returnRightPointer() != NULL)
    {
        rightDepth = rightDepth + 1;
        rightComparisonNode = findSmallestNode(thePointer -> returnRightPointer(),rightDepth);
    }

    if (leftDepth > rightDepth)
    {
        depth = leftDepth;
        return leftComparisonNode;
    }
    else
    {
        depth = rightDepth;
        return rightComparisonNode;
    }
}

void AVLTree::interface()
{
    while (1)
    {
        int command;
        std::cout << "Select An Option:" << std::endl;
        std::cout << "1. Add a Value 2. Print Pre-Order 3. Print Post-Order 4. In-Order 5. Groot" << std::endl;
        std::cin >> command;
        switch(command)
        {
        case 1:
            std::cout << "Input number: ";
            std::cin >> command;
            addToTree(command);
            break;
        case 2:
            std::cout << std::endl;
            printTree(2);
            break;
        case 3:
            std::cout << std::endl;
            printTree(3);
            break;
        case 4:
            std::cout << std::endl;
            printTree(1);
            break;
        case 5:
            std::cout << std::endl;
            printTree(4);
            break;
        case 6:
            std::cin >> command;
            deleteNode(command,headNode);
            break;
        default:
            std::cout << "Invalid Command" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return;
}


node* AVLTree::findPreviousNode(node * targetNode, node * currentNode)
{
    node * traverseNode = currentNode;
    if (traverseNode == targetNode)
    {
        return traverseNode;
    }
    else if (traverseNode -> returnLeftPointer() == targetNode)
    {
        return traverseNode;
    }
    else if (traverseNode -> returnRightPointer() == targetNode)
    {
        return traverseNode;
    }
    findPreviousNode(targetNode,traverseNode -> returnLeftPointer());
    findPreviousNode(targetNode,traverseNode -> returnRightPointer());
}
