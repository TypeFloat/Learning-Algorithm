#include <vector>

#include "util.h"

using namespace std;

vector<vector<int>> combine(int n, int k) {
    // 递归停止条件
    if (n < k) return {};
    if (k == 1) {
        vector<vector<int>> nums;
        for (int i = 1; i <= n; ++i) nums.push_back({i});
        return nums;
    }
    // 不取n
    vector<vector<int>> nums1 = combine(n - 1, k);
    // 取n
    vector<vector<int>> nums2 = combine(n - 1, k - 1);
    for (vector<int> &num : nums2) {
        num.push_back(n);
        nums1.push_back(num);
    }
    return nums1;
}

int main(int argc, char **argv) {
    int n = 4, k = 2;
    vector<vector<int>> nums = combine(4, 2);
}