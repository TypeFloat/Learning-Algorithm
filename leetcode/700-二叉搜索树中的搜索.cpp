#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != nullptr)
    {
        if (root->val == val)
            return root;
        else if (root->val < val)
        {
            if (root->right != nullptr)
                root = root->right;
            else
                root = nullptr;
        }
        else
        {
            if (root->left != nullptr)
                root = root->left;
            else
                root = nullptr;
        }
    }
    return root;
}