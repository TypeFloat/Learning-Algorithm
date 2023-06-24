#include "utils.h"
#include "tree.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    int count = 1;
    vector<vector<int>> rtn;
    while (!my_queue.empty())
    {
        vector<int> layer;
        int tmp = 0;
        for (int i = 0; i < count; ++i)
        {
            TreeNode *tmp_ptr = my_queue.front();
            layer.emplace_back(tmp_ptr->val);
            if (tmp_ptr->left != nullptr)
            {
                my_queue.push(tmp_ptr->left);
                tmp++;
            }
            if (tmp_ptr->right != nullptr)
            {
                my_queue.push(tmp_ptr->right);
                tmp++;
            }
            my_queue.pop();
        }
        count = tmp;
        rtn.emplace_back(layer);
    }
    return rtn;
}

void solution(vector<int> &val_num, vector<vector<int>> &target)
{
    BinaryTree tree(val_num);
    check(levelOrder(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    vector<vector<int>> target;

    // case 1
    val_num = {3, 9, -1, -1, 20, 15, -1, -1, 7};
    target = {{3}, {9, 20}, {15, 7}};
    solution(val_num, target);

    // case 2
    val_num = {1};
    target = {{1}};
    solution(val_num, target);

    // case 3
    val_num = {};
    target = {};
    solution(val_num, target);
}