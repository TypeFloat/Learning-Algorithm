#include "utils.h"
#include "tree.h"

using namespace std;

vector<int> largestValues(TreeNode *root)
{   
    if (root == nullptr)
        return {};
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    int count = 1;
    vector<int> rtn;
    while (!my_queue.empty())
    {
        int max_num = INT_MIN;
        int tmp = 0;
        for (int i = 0; i < count; ++i)
        {
            TreeNode *tmp_ptr = my_queue.front();
            max_num = max(max_num, tmp_ptr->val);
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
        rtn.emplace_back(max_num);
        count = tmp;
    }
    return rtn;
}

void solution(vector<int> val_num, vector<int> target)
{
    BinaryTree tree(val_num);
    check(largestValues(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num, target;

    // case 1
    val_num = {1, 3, 2, -1, -1, 3, -1, -1, 2, -1, 9};
    target = {1, 3, 9};
    solution(val_num, target);

    // case 2
    val_num = {1, 2, -1, -1, 3};
    target = {1, 3};
    solution(val_num, target);
}