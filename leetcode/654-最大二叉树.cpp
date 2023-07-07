#include "utils.h"
#include "tree.h"

using namespace std;

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    if (nums.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode();
    int max_index;
    int max_val = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > max_val)
        {
            max_val = nums[i];
            max_index = i;
        }
    }
    root->val = max_val;
    vector<int> left_nums(nums.begin(), nums.begin() + max_index);
    vector<int> right_nums(nums.begin() + max_index + 1, nums.end());
    root->left = constructMaximumBinaryTree(left_nums);
    root->right = constructMaximumBinaryTree(right_nums);
    return root;
}