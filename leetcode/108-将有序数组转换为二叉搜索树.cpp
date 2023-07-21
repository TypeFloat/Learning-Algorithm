#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0) return nullptr;
    TreeNode *root = new TreeNode();
    int mid = nums.size() / 2;
    root->val = nums[mid];
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid + 1, nums.end());
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}

int main(int argc, char **argv) {
    vector<int> val_num = {-10, -3, 0, 5, 9};
    sortedArrayToBST(val_num);
}