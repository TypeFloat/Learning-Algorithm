#include "utils.h"
#include "tree.h"

using namespace std;

int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left_depth = 0, right_depth = 0;
    TreeNode *tmp = root;
    while (tmp != nullptr)
    {
        tmp = tmp->left;
        left_depth++;
    }
    tmp = root;
    while (tmp != nullptr)
    {
        tmp = tmp->right;
        right_depth++;
    }
    if (left_depth == right_depth)
        return static_cast<int>(pow(2, left_depth) - 1);
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

void solution(vector<int> val_num, int target)
{
    BinaryTree tree(val_num);
    check(countNodes(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    int target;

    // case 1
    val_num = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6};
    target = 6;
    solution(val_num, target);

    // case 2
    val_num = {};
    target = 0;
    solution(val_num, target);

    // case 3
    val_num = {1};
    target = 1;
    solution(val_num, target);
}