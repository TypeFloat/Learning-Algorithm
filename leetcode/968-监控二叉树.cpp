#include "tree.h"
#include "utils.h"

using namespace std;

static int count = 0;

int traversal(TreeNode *root, int &count) {
    if (root == nullptr) return 2;
    int left_status = traversal(root->left, count);
    int right_status = traversal(root->right, count);
    if (left_status == 0 || right_status == 0) {
        ++count;
        return 1;
    } else if (left_status == 2 && right_status == 2)
        return 0;
    return 2;
}

int minCameraCover(TreeNode *root) {
    int count = 0;
    int status = traversal(root, count);
    if (status == 0) ++count;
    return count;
}