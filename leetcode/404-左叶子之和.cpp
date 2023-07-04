#include "utils.h"
#include "tree.h"

using namespace std;

int sumOfLeftLeaves(TreeNode *root)
{
    stack<TreeNode *> my_stack;
    my_stack.push(root);
    int sum = 0;
    while (!my_stack.empty())
    {
        TreeNode *tmp = my_stack.top();
        my_stack.pop();
        if (tmp->left != nullptr)
        {
            if (tmp->left->left == nullptr && tmp->left->right == nullptr)
                sum += tmp->left->val;
            else
                my_stack.push(tmp->left);
        }
        if (tmp->right != nullptr && 
            !(tmp->right->left == nullptr && tmp->right->right == nullptr))
            my_stack.push(tmp->right);
    }
    return sum;
}

void solution(vector<int> val_num, int target)
{
    BinaryTree tree(val_num);
    check(sumOfLeftLeaves(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    int target;

    // case 1
    val_num = {3, 9, -1, -1, 20, 15, -1, -1, 7};
    target = 24;
    solution(val_num, target);

    // case 2
    val_num = {1};
    target = 0;
    solution(val_num, target);
}