#include "utils.h"
#include "tree.h"

using namespace std;

int findBottomLeftValue(TreeNode *root)
{
    vector<int> nums;
    queue<TreeNode *> my_queue;
    int count, tmp;
    TreeNode *tmp_node;
    my_queue.push(root);
    count = 1;
    while (!my_queue.empty())
    {
        tmp = 0;
        nums.clear();
        for (int i = 0; i < count; ++i)
        {
            tmp_node = my_queue.front();
            my_queue.pop();
            if (tmp_node->left != nullptr)
            {
                my_queue.push(tmp_node->left);
                tmp++;
            }
            if (tmp_node->right != nullptr)
            {
                my_queue.push(tmp_node->right);
                tmp++;
            }
            nums.emplace_back(tmp_node->val);
        }
        count = tmp;
    }
    return nums[0];
}

void solution(vector<int> val_num, int target)
{
    BinaryTree tree(val_num);
    check(findBottomLeftValue(tree.root), target);
}

int main(int argc, char **argv)
{
    vector<int> val_num;
    int target;

    // case 1
    val_num = {2, 1, -1, -1, 3};
    target = 1;
    solution(val_num, target);

    // case 2
    val_num = {1, 2, 4, -1, -1, -1, 3, 5, 7, -1, -1, 6};
    target = 7;
    solution(val_num, target);
}