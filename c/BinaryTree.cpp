#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    /// init
    root = 0;
}

void BinaryTree::addNode(int value) {
    TreeNode *node = new TreeNode(value);

    if (root == 0) {
        root = node;
    } else {
        TreeNode *curr = root;

        do {
            if (value < curr->value) {
                if (curr->left) {
                    curr = curr->left;
                } else {
                    curr->left = node;
                    curr = 0;
                }
            } else {
                if (curr->right) {
                    curr = curr->right;
                } else {
                    curr->right = node;
                    curr = 0;
                }
            }
        } while (curr);
    }
}

void BinaryTree::visitDF(TreeNode *node) {
    if (node) {
        visitDF(node->left);
        std::cout << node->value << std::endl;
        visitDF(node->right);
    }
}

void BinaryTree::visitBF(TreeNode *node) {
    std::queue<TreeNode *> fifo;

    fifo.push(node);

    while (fifo.front()) {
        TreeNode *temp = fifo.front();
        fifo.pop();

        std::cout << temp->value << std::endl;

        if (temp->left) fifo.push(temp->left);
        if (temp->right) fifo.push(temp->right);
    }
}

void BinaryTree::traverse() {
    if (root) {
        visitDF(root);
        visitBF(root);
    }
}
