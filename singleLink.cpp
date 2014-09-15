#include "singleLink.h"


Node::Node()
{
    NextPointer = NULL;
}


Node::~Node()
{

}


customer Node::returnData()
{
    return storedCustomer;
}


void Node::setData(customer customer)
{
    storedCustomer = customer;
    return;
}


Node * Node::returnNextPointer()
{
    return NextPointer;
}


void Node::setNextPointer(Node * newPointer)
{
    NextPointer = newPointer;
    return;
}


singleLink::singleLink()
{
    headNode = NULL;
}


singleLink::~singleLink()
{
    if (headNode != NULL)
    {
        Node * traverseNode = headNode;
        Node * previousNode = NULL;
        while (traverseNode != NULL)
        {
            previousNode = traverseNode;
            traverseNode = traverseNode -> returnNextPointer();
            delete previousNode;
            previousNode = NULL;
        }
    }
}


void singleLink::Add(customer newCustomer)
{
    if (headNode == NULL)
    {
        Node * newNode = new Node;
        newNode -> setData(newCustomer);
        newNode -> setNextPointer(NULL);
        headNode = newNode;
    }
    else
    {
        Node * newNode = new Node;
        newNode -> setData(newCustomer);
        newNode -> setNextPointer(headNode);
        headNode = newNode;
    }
    return;
}


customer singleLink::Remove()
{
    customer returnedCustomer;
    if (headNode == NULL)
    {
        //std::cout << "List is Empty";
        //Nothing
        headNode = NULL;
        return returnedCustomer;
    }
    else
    {
        Node * traverseNode = headNode;
        if (traverseNode -> returnNextPointer() == NULL)
        {
            returnedCustomer = headNode -> returnData();
            delete headNode;
            headNode = NULL;
            return returnedCustomer;
        }

        while(traverseNode -> returnNextPointer() -> returnNextPointer() != NULL)
        {
            traverseNode = traverseNode -> returnNextPointer();
        }

        returnedCustomer = traverseNode -> returnData();
        traverseNode -> setNextPointer(NULL);
        return returnedCustomer;

    }
}


std::vector<customer> singleLink::returnVector()
{

    std::vector<customer> returnedVector;
    Node * traverseNode = headNode;

    while(traverseNode != NULL)
    {
        //std::cout << "Ok";
        //customer currentCustomer = traverseNode -> returnData();
        traverseNode = traverseNode -> returnNextPointer();
    }

    return returnedVector;
}

void singleLink::updateTime()
{
    if (headNode != NULL)
    {
        Node * traverseNode = headNode;
        while (traverseNode != NULL)
        {
            customer currentCustomer = traverseNode -> returnData();
            currentCustomer.incrementWaitTime();
            traverseNode -> setData(currentCustomer);
            traverseNode = traverseNode -> returnNextPointer();
        }
    }
    return;
}

int singleLink::returnSize()
{
    int counter = 0;
    if (headNode != NULL)
    {
        Node * traverseNode = headNode;
        while(traverseNode != NULL)
        {
            counter++;
            traverseNode = traverseNode -> returnNextPointer();
        }
    }

    return counter;
}
