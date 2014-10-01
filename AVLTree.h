#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinaryTree.h"


class AVLTree : public BinaryTree
{
    public:
        AVLTree();
        virtual ~AVLTree();
        node * leftRotate(node * thePointer);
        node * rightRotate(node * thePointer);
        void addToTree(int);
        int checkBalance(node * thePointer);
        int returnHeight(node * thePointer);
        int deleteNode(int target, node * thePointer);
        void interface();
        node * findPreviousNode(node * targetNode, node * currentNode);
    protected:
    private:
        node * findSmallestNode(node* thePointer,int &depth);
};

#endif // AVLTREE_H
