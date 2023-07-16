#include <cstddef>
#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

vector<int> findMode(TreeNode *root) {
    vector<int> result;
    int max_count = 0;
    int num = -1, count = -1;
    stack<TreeNode *> my_stack;
    do {
        while (root != nullptr) {
            my_stack.push(root);
            root = root->left;
        }
        root = my_stack.top();
        my_stack.pop();

        // 与当前记录的数相同
        if (root->val == num) count++;
        // 与当前记录的数不同
        else {
            // 出现次数比历史最大值还大
            if (count > max_count) {
                result.clear();
                result.push_back(num);
                max_count = count;
            }
            // 出现次数与历史值相同
            else if (count == max_count)
                result.push_back(num);
            num = root->val;
            count = 1;
        }

        root = root->right;

    } while (root != nullptr || !my_stack.empty());
    if (count > max_count)
        return {num};
    else if (count == max_count)
        result.push_back(num);
    return result;
}

void solution(vector<int> val_num, vector<int> target) {
    BinaryTree tree(val_num);
    check(findMode(tree.root), target);
}

int main(int argc, char **argv) {
    vector<int> val_num, target;

    // case 1
    val_num = {1, -1, 2, 2};
    target = {2};
    solution(val_num, target);

    // case 2
    val_num = {0};
    target = {0};
    solution(val_num, target);
}