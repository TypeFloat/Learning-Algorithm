#include <vector>

#include "utils.h"

using namespace std;

vector<vector<int>> recursive(int k, int n, int sum) {
    if (n < k) return {};
    if (sum < (1 + k) * k / 2) return {};
    if (sum > (2 * n - k + 1) * k / 2) return {};
    if (k == 1) {
        if (n >= sum)
            return {{sum}};
        else
            return {};
    }
    vector<vector<int>> nums1 = recursive(k - 1, n - 1, sum - n);
    vector<vector<int>> nums2 = recursive(k, n - 1, sum);
    for (vector<int> nums : nums1) {
        nums.push_back(n);
        nums2.push_back(nums);
    }
    return nums2;
}

vector<vector<int>> combinationSum3(int k, int n) { return recursive(k, 9, n); }

int main(int argc, char **argv) {
    vector<vector<int>> nums = combinationSum3(3, 9);
}