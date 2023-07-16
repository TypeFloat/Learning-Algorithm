#include <climits>
#include <cstddef>
#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

int getMinimumDiffereencee(TreeNode *root) {
    int min_diff = INT_MAX;
    int left_val = -100000;
    vector<int> rtn;
    stack<TreeNode *> my_stack;
    do {
        while (root != nullptr) {
            my_stack.push(root);
            root = root->left;
        }
        root = my_stack.top();
        my_stack.pop();
        min_diff = min(min_diff, root->val - left_val);
        left_val = root->val;
        root = root->right;
    } while (root != nullptr || !my_stack.empty());
    return min_diff;
}

void solution(vector<int> val_num, int target) {
    BinaryTree tree(val_num);
    check(getMinimumDiffereencee(tree.root), target);
}

int main(int argc, char **argv) {
    vector<int> val_num;
    int target;

    // case 1
    val_num = {4, 2, 1, -1, -1, 3, -1, -1, 6};
    target = 1;
    solution(val_num, target);

    // case 2
    val_num = {1, 0, -1, -1, 48, 12, -1, -1, 49};
    target = 1;
    solution(val_num, target);
}