#include "util.h"
#include "tree.h"

using namespace std;

bool isSymmetric(TreeNode *root)
{
    stack<TreeNode *> left, right;
    left.push(root->left);
    right.push(root->right);
    TreeNode *tmp_left, *tmp_right;
    while (!left.empty() && !right.empty())
    {
        tmp_left = left.top();
        tmp_right = right.top();
        left.pop();
        right.pop();
        if (tmp_left == nullptr && tmp_right == nullptr)
            continue;
        if ((tmp_left == nullptr && tmp_right != nullptr) || 
            (tmp_left != nullptr && tmp_right == nullptr))
            return false;
        if (tmp_left->val != tmp_right->val)
            return false;
        left.push(tmp_left->right);
        left.push(tmp_left->left);
        right.push(tmp_right->left);
        right.push(tmp_right->right);
    }
    return true;
}

void solution(vector<int> val_num, bool target)
{
    BinaryTree tree(val_num);
    check(isSymmetric(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;

    // case 1
    val_num = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3};
    solution(val_num, true);

    // case 2
    val_num = {1, 2, -1, 3, -1, -1, 2, -1, 3};
    solution(val_num, false);
}