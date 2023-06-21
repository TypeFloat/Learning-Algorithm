#include "utils.h"
#include "tree.h"

using namespace std;

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int max_depth = 0;
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    my_queue.push(nullptr);
    TreeNode *ptr;
    bool flag;

    while (!my_queue.empty())
    {
        while (true)
        {
            ptr = my_queue.front();
            my_queue.pop();
            if (ptr == nullptr)
                break;
                
            flag = true;
            if (ptr->left != nullptr)
                my_queue.push(ptr->left);
            if (ptr->right != nullptr)
                my_queue.push(ptr->right);
        }
        if (flag)
        {
            my_queue.push(nullptr);
            flag = false;
            max_depth++;
        }
    }
    return max_depth;
}

void solution(vector<int> &val_list, int target)
{
    BinaryTree tree(val_list);
    check(maxDepth(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_list;
    int target;

    // case 1
    val_list = {3, 9, -1, -1, 20, 15, -1, -1, 7};
    target = 3;
    solution(val_list, target);
}