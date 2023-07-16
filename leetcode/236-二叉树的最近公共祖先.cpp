#include <stack>
#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

vector<TreeNode *> findNode(TreeNode *root, TreeNode *p) {
    vector<TreeNode *> path = {};
    if (root == p)
        path.push_back(root);
    else if (root != nullptr) {
        vector<TreeNode *> sub_path = findNode(root->left, p);
        if (sub_path.size() == 0) sub_path = findNode(root->right, p);
        if (sub_path.size() != 0) {
            path.push_back(root);
            for (TreeNode *num : sub_path) path.push_back(num);
        }
    }
    return path;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> left_path = findNode(root, p);
    vector<TreeNode *> right_path = findNode(root, q);
    auto left = left_path.begin();
    auto right = right_path.begin();
    while (*left == *right) {
        if (left + 1 != left_path.end())
            left++;
        else
            return *left;
        if (right + 1 != right_path.end())
            right++;
        else
            return *right;
    }
    return *(--left);
}

int main(int argc, char **argv) {
    vector<int> val_num = {3, 5,  6,  -1, -1, 2,  7,  -1, -1,
                           4, -1, -1, 1,  0,  -1, -1, 8};
    BinaryTree tree(val_num);
    TreeNode *node = lowestCommonAncestor(tree.root, tree.root->left,
                                          tree.root->right->right);
}