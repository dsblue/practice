#ifndef PRACTICE_BINARYTREE_H
#define PRACTICE_BINARYTREE_H

#include <ostream>
#include <iostream>
#include <queue>

class TreeNode {

public:

    int value;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) {
        this->value = value;
        left = 0;
        right = 0;
    }
};

class BinaryTree {
private:
    TreeNode *root;

public:

    BinaryTree() ;

    void addNode(int value) ;

    void visitDF(TreeNode *node);

    void visitBF(TreeNode *node);

    void traverse();

};


#endif //PRACTICE_BINARYTREE_H
