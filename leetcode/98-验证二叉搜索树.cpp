#include <vector>

#include "tree.h"
#include "utils.h"

using namespace std;

bool isValidBST(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;  // 记录前一个节点
    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;  // 左
        } else {
            cur = st.top();  // 中
            st.pop();
            if (pre != nullptr && cur->val <= pre->val) return false;
            pre = cur;  // 保存前一个访问的结点

            cur = cur->right;  // 右
        }
    }
    return true;
}

int main(int argc, char **argv) {
    vector<int> val_num = {2, 1, -1, -1, 3};
    BinaryTree tree(val_num);
    bool target = isValidBST(tree.root);
}
