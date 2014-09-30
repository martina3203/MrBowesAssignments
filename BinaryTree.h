#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class node
{
public:
    node();
    ~node();
    int returnData();
    node * returnLeftPointer();
    node * returnRightPointer();
    void setData(int);
    void setLeftPointer(node*);
    void setRightPointer(node*);
private:
    int data;
    node * leftPointer;
    node * rightPointer;
};





class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        virtual void addToTree(int);
        void deleteNode(node * thePointer);
        //1 for In-Order, 2 for pre-order, 3 for post-order, 4 for Groot
        void printBranch(int theCode, node * thePointer);
        virtual void addToBranches(node * thePointer, int newData);
        node * headNode;
        void printTree(int code);
        void interface();
    protected:

    private:
};




#endif // BINARYTREE_H
