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
    thePointer -> setLeftPointer(temp -> returnRightPointer());
    temp -> setRightPointer(thePointer);
    return temp;
}

node * AVLTree::leftRotate(node * thePointer)
{
    //Set Temp equal to the Right Pointer
    node * temp = thePointer -> returnRightPointer();
    //Right Pointer becomes the left pointer the Pointer's right child.
    thePointer -> setRightPointer(temp -> returnLeftPointer());
    //The previous right pointer becomes the the left pointer of the right child's
    temp -> setLeftPointer(thePointer);
    return temp;
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
            leftValue = 1 + checkBalance(thePointer -> returnLeftPointer());
        }
        //Checks right value
        if (thePointer -> returnRightPointer() != NULL)
        {
            rightValue = checkBalance(thePointer -> returnRightPointer()) - 1;
        }
        returnValue = leftValue + rightValue;
        //std::cout << "N" << returnValue << std::endl;
        //Left Rotation Needed
        if (returnValue > 1)
        {
            std::cout << "Unbalanced Tree ";
            node * currentNode = thePointer -> returnLeftPointer();
            if (checkBalance(currentNode) == -1)
            {
                leftRotate(currentNode);
                std::cout << "Double Left Performed" << std::endl;
            }
            else
            {
                std::cout << "Single Right Performed" << std::endl;
            }
            rightRotate(currentNode);
        }
        //Right Rotation Needed
        else if (returnValue < -1)
        {
            std::cout << "Unbalanced Tree ";
            node * currentNode = thePointer -> returnRightPointer();
            if (checkBalance(currentNode -> returnRightPointer()) == 1)
            {
                rightRotate(currentNode -> returnRightPointer());
                std::cout << "Double Right Performed" << std::endl;
            }
            else
            {
                std::cout << "Single Left Performed" << std::endl;
            }
            leftRotate(currentNode);
        }

        return returnValue;
    }
    else
    {
        return 0;
    }
}
