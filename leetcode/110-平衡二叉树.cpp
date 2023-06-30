#include "utils.h"
#include "tree.h"

using namespace std;

int getHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left_height = getHeight(root->left);
    if (left_height == -1)
        return left_height;
    int right_height = getHeight(root->right);
    if (right_height == -1)
        return right_height;
    int height = abs(left_height - right_height);
    if (height > 1)
        return -1;
    else
        return max(left_height, right_height) + 1;
}

bool isBalanced(TreeNode *root)
{
    return getHeight(root) == -1 ? false : true;
}

void solution(vector<int> val_num, bool target)
{
    BinaryTree tree(val_num);
    check(isBalanced(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    bool target;

    // case 1
    val_num = {3, 9, -1, -1, 20, 15, -1, -1, 7};
    target = true;
    solution(val_num, target);

    // case 2
    val_num = {1, 2, 3, 4, -1, -1, 4, -1, -1, 3, -1, -1, 2, -1, -1};
    target = false;
    solution(val_num, target);

    // case 3
    val_num = {};
    target = true;
    solution(val_num, target);
}