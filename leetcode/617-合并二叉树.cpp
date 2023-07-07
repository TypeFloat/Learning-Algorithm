#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;
    else if (root1 != nullptr && root2 != nullptr)
    {
        TreeNode *root = new TreeNode();
        root->val = root1->val + root2->val;
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
    else
        return root1 == nullptr ? root2 : root1;
}

int main(int argc, char **argv)
{
    vector<int> val_num = {1, 3, 5, -1, -1, -1, 2};
    BinaryTree root1(val_num);
    val_num = {2, 1, -1, 4, -1, -1, 3, -1, 7};
    BinaryTree root2(val_num);
    TreeNode *root = mergeTrees(root1.root, root2.root);
}