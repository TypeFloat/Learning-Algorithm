#include "tree.h"
#include "utils.h"

using namespace std;

TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
        root = new TreeNode();
        root->val = val;
        return root;
    }

    TreeNode *ptr = root;
    while (true) {
        if (ptr->val > val) {
            if (ptr->left != nullptr)
                ptr = ptr->left;
            else {
                TreeNode *node = new TreeNode();
                node->val = val;
                ptr->left = node;
                break;
            }
        } else {
            if (ptr->right != nullptr)
                ptr = ptr->right;
            else {
                TreeNode *node = new TreeNode();
                node->val = val;
                ptr->right = node;
                break;
            }
        }
    }
    return root;
}