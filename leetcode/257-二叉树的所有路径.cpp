#include "utils.h"
#include "tree.h"

using namespace std;

vector<string> binaryTreePaths(TreeNode *root)
{
    stack<TreeNode *> node_stack;
    stack<string> str_stack;
    node_stack.push(root);
    str_stack.push("");
    vector<string> rtn;
    while (!node_stack.empty())
    {
        string tmp = str_stack.top();
        TreeNode *node = node_stack.top();
        str_stack.pop();
        node_stack.pop();
        tmp += "->";
        tmp += to_string(node->val);
        if (node->right != nullptr)
        {
            node_stack.push(node->right);
            str_stack.push(tmp);
        }
        if (node->left != nullptr)
        {
            node_stack.push(node->left);
            str_stack.push(tmp);
        }
        if (node->left == nullptr && node->right == nullptr)
            rtn.emplace_back(tmp.substr(2, tmp.size()-2));
    }
    return rtn;
}

void solution(vector<int> val_num, vector<string> target)
{
    BinaryTree tree(val_num);
    check(binaryTreePaths(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    vector<string> target;

    // case 1
    val_num = {1, 2, -1, 5, -1, -1, 3};
    target = {"1->2->5", "1->3"};
    solution(val_num, target);

    // case 2
    val_num = {1};
    target = {"1"};
    solution(val_num, target);
}