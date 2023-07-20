#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (root == nullptr) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main(int argc, char **argv) {
    vector<int> val_num = {2, 1, -1, -1, 3};
    BinaryTree tree(val_num);
    TreeNode *node = trimBST(tree.root, 3, 4);
}