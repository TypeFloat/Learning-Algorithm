#include "utils.h"
#include "tree.h"

using namespace std;

vector<double> averageOfLevels(TreeNode *root)
{
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    int count = 1;
    vector<double> rtn;
    while (!my_queue.empty())
    {
        double sum = 0.0;
        int tmp = 0;
        for (int i = 0; i < count; ++i)
        {
            TreeNode *tmp_ptr = my_queue.front();
            sum += tmp_ptr->val;
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
        rtn.emplace_back(sum/count);
        count = tmp;
    }
    return rtn;
}

void solution(vector<int> val_num, vector<double> target)
{
    BinaryTree tree(val_num);
    check(averageOfLevels(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    vector<double> target;

    // case 1
    val_num = {3, 9, -1, -1, 20, 15, -1, -1, 7};
    target = {3.00000, 14.50000, 11.00000};
    solution(val_num, target);

    // case 2
    val_num = {3, 9, 15, -1, -1, 7, -1, -1, 20};
    target = {3.00000, 14.5000, 11.00000};
    solution(val_num, target); 
}