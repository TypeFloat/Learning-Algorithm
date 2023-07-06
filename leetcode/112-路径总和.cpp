#include "utils.h"
#include "tree.h"

using namespace std;

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    stack<TreeNode *> node_stack;
    stack<int> sum_stack;
    node_stack.push(root);
    sum_stack.push(0);
    while (!node_stack.empty())
    {
        int tmp = sum_stack.top();
        TreeNode *node = node_stack.top();
        sum_stack.pop();
        node_stack.pop();
        tmp += node->val;
        if (node->right != nullptr)
        {
            node_stack.push(node->right);
            sum_stack.push(tmp);
        }
        if (node->left != nullptr)
        {
            node_stack.push(node->left);
            sum_stack.push(tmp);
        }
        if (node->left == nullptr && node->right == nullptr && tmp == targetSum)
            return true;
    }
    return false;
}

void solution(vector<int> val_num, int target, bool ans)
{
    BinaryTree tree(val_num);
    check(hasPathSum(tree.root, target), ans);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    int target;
    bool ans;

    // case 1
    val_num = {5, 4, 11, 7, -1, -1, 2, -1, -1, -1, 8, 13, -1, -1, 4, -1, 1};
    target = 22;
    ans = true;
    solution(val_num, target, ans);

    // case 2
    val_num = {1, 2, -1, -1, 3};
    target = 5;
    ans = false;
    solution(val_num, target, ans);

    // case 3
    val_num = {};
    target = 0;
    ans = false;
    solution(val_num, target, ans);
}