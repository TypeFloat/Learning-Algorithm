#include <stack>
#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

vector<TreeNode *> findNode(TreeNode *root, TreeNode *p) {
    vector<TreeNode *> path = {};
    if (root != nullptr) {
        if (root == p) return {root};
        vector<TreeNode *> sub_path;
        if (root->val > p->val)
            sub_path = findNode(root->left, p);
        else
            sub_path = findNode(root->right, p);
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
    vector<int> val_num = {6, 2,  0,  -1, -1, 4,  3,  -1, -1,
                           5, -1, -1, 8,  7,  -1, -1, 9};
    BinaryTree tree(val_num);
    TreeNode *node = lowestCommonAncestor(tree.root, tree.root->left,
                                          tree.root->right->right);
}