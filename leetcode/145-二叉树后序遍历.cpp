#include "utils.h"
#include "tree.h"

using namespace std;

vector<int> postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    stack<TreeNode *> my_stack;
    my_stack.push(root);
    vector<int> rtn;
    TreeNode *ptr;
    while (!my_stack.empty())
    {
        ptr = my_stack.top();
        my_stack.pop();
        rtn.emplace_back(ptr->val);
        if (ptr->left != nullptr)
            my_stack.push(ptr->left);
        if (ptr->right != nullptr)
            my_stack.push(ptr->right);
    }
    reverse(rtn.begin(), rtn.end());
    return rtn;
}

void solution(vector<int> &target, vector<int> &val_list)
{
    BinaryTree tree(val_list);
    check(postorderTraversal(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> target, val_list;
    
    // case 1
    val_list = {1, -1, 2, 3};
    target = {3, 2, 1};
    solution(target, val_list);

    // case 2
    val_list = {};
    target = {};
    solution(target, val_list);

    // case 3
    val_list = {1};
    target = {1};
    solution(target, val_list);
}