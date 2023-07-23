#include <cstddef>
#include <ios>
#include <stack>
#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

TreeNode *convertBST(TreeNode *root) {
    if (root == nullptr) return root;
    stack<TreeNode *> my_stack;
    TreeNode *tmp = root;
    int num = 0;
    do {
        while (tmp != nullptr) {
            my_stack.push(tmp);
            tmp = tmp->right;
        }
        tmp = my_stack.top();
        my_stack.pop();
        tmp->val += num;
        num = tmp->val;
        tmp = tmp->left;
    } while (!my_stack.empty() || tmp != nullptr);
    return root;
}

int main(int argc, char **argv) {
    vector<int> val_num = {4,  1, 0, -1, -1, 2, -1, 3, -1,
                           -1, 6, 5, -1, -1, 7, -1, 8};
    BinaryTree tree(val_num);
    TreeNode *node = convertBST(tree.root);
}