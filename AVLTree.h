#ifndef AVLTREE_H
#define AVLTREE_H

#include <BinaryTree.h>


class AVLTree : public BinaryTree
{
    public:
        AVLTree();
        virtual ~AVLTree();
        node * leftRotate(node * thePointer);
        node * rightRotate(node * thePointer);
        void addToTree(int);
        int checkBalance(node * thePointer);
    protected:
    private:
};

#endif // AVLTREE_H
