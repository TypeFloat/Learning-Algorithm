#include "utils.h"
#include "tree.h"

using namespace std;

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<TreeNode *> my_stack;
    my_stack.push(root);
    int count = 1;
    int depth = 0;
    while (!my_stack.empty())
    {
        int tmp = 0;
        TreeNode *tmp_node;
        for (int i = 0; i < count; ++i)
        {
            tmp_node = my_stack.front();
            my_stack.pop();
            if (tmp_node->left == nullptr && tmp_node->right == nullptr)
                return depth + 1;
            if (tmp_node->left != nullptr)
            {
                my_stack.push(tmp_node->left);
                tmp++;
            }
            if (tmp_node->right != nullptr)
            {
                my_stack.push(tmp_node->right);
                tmp++;
            }
        }
        count = tmp;
        depth++;
    }
    return depth;
}

void solution(vector<int> val_num, int target)
{
    BinaryTree tree(val_num);
    check(minDepth(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    int target;

    // case 1
    val_num = {3, 9, -1, -1, 20, 15, -1, -1, 7};
    target = 2;
    solution(val_num, target);

    // case 2
    val_num = {2, -1, 3, -1, 4, -1, 5, -1, 6};
    target = 5;
    solution(val_num, target);
    
    // case 3
    val_num = {1, 2, 4, -1, -1, -1, 3, -1, 5};
    target = 3;
    solution(val_num, target); 
}