#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode;
    root->val = preorder[0];
    if (preorder.size() == 1)
        return root;
    int i;
    for (i = 0; i < inorder.size(); ++i)
    {
        if (inorder[i] == preorder[0])
            break;
    }
    vector<int> left_inorder(inorder.begin(), inorder.begin() + i);
    vector<int> right_inorder(inorder.begin() + i + 1, inorder.end());
    vector<int> left_preorder(preorder.begin() + 1,
                              preorder.begin() + 1 + left_inorder.size());
    vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(),
                               preorder.end());
    root->left = buildTree(left_preorder, left_inorder);
    root->right = buildTree(right_preorder, right_inorder);
    return root;
}

int main(int argc, char **argv)
{
    vector<int> preorder = {3, 9, 20, 15, 7},
                inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
}