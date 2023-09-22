#include "tree.h"
#include "utils.h"

using namespace std;

unordered_map<TreeNode *, int> umap;
int rob(TreeNode *root) {
    if (root == nullptr) return 0;
    if (umap[root]) return umap[root];
    int num1 = rob(root->left) + rob(root->right);
    int num2 = root->val;
    if (root->left != nullptr) {
        num2 += rob(root->left->left);
        num2 += rob(root->left->right);
    }
    if (root->right != nullptr) {
        num2 += rob(root->right->left);
        num2 += rob(root->right->right);
    }
    umap[root] = num1 > num2 ? num1 : num2;
    return umap[root];
}