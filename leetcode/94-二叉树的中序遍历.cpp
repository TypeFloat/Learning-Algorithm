#include "utils.h"
#include "tree.h"

using namespace std;

vector<int> inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> rtn;
    stack<TreeNode *> my_stack;
    do
    {
        while (root != nullptr)
        {
            my_stack.push(root);
            root = root->left;
        }
        root = my_stack.top();
        my_stack.pop();
        rtn.emplace_back(root->val);
        root = root->right;
    } while (root != nullptr || !my_stack.empty());
    return rtn;
}

void solution(vector<int> &target, vector<int> &val_list)
{
    BinaryTree tree(val_list);
    check(inorderTraversal(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> target, val_list;
    
    // case 1
    val_list = {1, -1, 2, 3};
    target = {1, 3, 2};
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