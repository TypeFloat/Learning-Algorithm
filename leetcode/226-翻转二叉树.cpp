#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
       return root;
    TreeNode *ptr = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(ptr);
    return root;
}