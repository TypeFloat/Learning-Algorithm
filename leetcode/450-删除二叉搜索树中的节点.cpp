#include "tree.h"
#include "utils.h"

using namespace std;

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return root;
    if (root->val == key) {
        if (root->left == nullptr && root->right == nullptr)
            return nullptr;
        else if (root->left == nullptr || root->right == nullptr)
            return root->left == nullptr ? root->right : root->left;
        else {
            TreeNode *node = root->right;
            while (node->left != nullptr) node = node->left;
            node->left = root->left;
            return root->right;
        }
    } else {
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
    }
    return root;
}