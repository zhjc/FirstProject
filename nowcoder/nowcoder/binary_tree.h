#pragma once

#include <vector>

class BinaryTree {
public:
    int val;
    BinaryTree* left;
    BinaryTree* right;

public:
    void PreOrder(BinaryTree* root, std::vector<BinaryTree*>& vecres) {
        if (root != NULL) {
            vecres.push_back(root);
            PreOrder(root->left, vecres);
            PreOrder(root->right, vecres);
        }
    }

    void IntOrder(BinaryTree* root, std::vector<BinaryTree*>& vecres) {
        if (root != NULL) {
            PreOrder(root->left, vecres);
            vecres.push_back(root);
            PreOrder(root->right, vecres);
        }
    }

    void PostOrder(BinaryTree* root, std::vector<BinaryTree*>& vecres) {
        if (root != NULL) {
            PreOrder(root->left, vecres);
            PreOrder(root->right, vecres);
            vecres.push_back(root);
        }
    }

    void PreOrder_recursive(BinaryTree* root, std::vector<BinaryTree*>& vecres) {

    }

    void IntOrder_recursive(BinaryTree* root, std::vector<BinaryTree*>& vecres) {

    }

    void PostOrder_recursive(BinaryTree* root, std::vector<BinaryTree*>& vecres) {

    }
};