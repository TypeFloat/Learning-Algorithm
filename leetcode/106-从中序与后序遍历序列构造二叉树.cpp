#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode();
    root->val = postorder[postorder.size() - 1];
    int i;
    for (i = 0; i < inorder.size(); ++i)
    {
        if (inorder[i] == root->val)
            break;
    }
    vector<int> left_inorder(inorder.begin(), inorder.begin() + i);
    vector<int> left_poster(postorder.begin(), postorder.begin() + i);
    vector<int> right_inorder(inorder.begin() + i + 1, inorder.end());
    vector<int> right_poster(postorder.begin() + i, postorder.end() - 1);
    root->left = buildTree(left_inorder, left_poster);
    root->right = buildTree(right_inorder, right_poster);
    return root;
}
