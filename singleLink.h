#ifndef SINGLELINK_H
#define SINGLELINK_H

#include <vector>
#include "customer.h"

class Node
{
public:
    Node();
    ~Node();
    customer returnData();
    void setData(customer);
    Node * returnNextPointer();
    void setNextPointer(Node *);
private:
    customer storedCustomer;
    Node * NextPointer;
};


class singleLink
{
    public:
        singleLink();
        virtual ~singleLink();
        void Add(customer);
        customer Remove();
        void updateTime();
        std::vector<customer> returnVector();
        int returnSize();
    protected:
    private:
        Node * headNode;
};

#endif // SINGLELINK_H
