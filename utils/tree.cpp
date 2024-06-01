#include "tree.h"

#include <stack>

BinaryTree::BinaryTree(std::vector<int> &val_list) {
    if (val_list.size() == 0) {
        this->root = nullptr;
        return;
    }
    std::stack<TreeNode **> my_stack;
    my_stack.push(&this->root);
    TreeNode **ptr;
    for (int val : val_list) {
        ptr = my_stack.top();
        my_stack.pop();
        if (val != -1) {
            *ptr = new TreeNode(val);
            my_stack.push(&((*ptr)->right));
            my_stack.push(&((*ptr)->left));
        }
    }
}

BinaryTree::~BinaryTree() {
    if (this->root == nullptr) return;
    std::stack<TreeNode *> my_stack;
    my_stack.push(this->root);
    TreeNode *ptr;
    while (!my_stack.empty()) {
        ptr = my_stack.top();
        my_stack.pop();
        if (ptr->left != nullptr) my_stack.push(ptr->left);
        if (ptr->right != nullptr) my_stack.push(ptr->right);
        delete ptr;
    }
}