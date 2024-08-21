#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_multiset<int> record;
        int sum = 0;
        record.insert(0);
        int rtn = 0;
        for (int num: nums) {
            sum += num;
            rtn += record.count(sum - k);
            record.insert(sum);
        }
        return rtn;
    }
};

void test(vector<int> &nums, int k, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.subarraySum(nums, k), ans);
}

TEST(Q560, CASE1) {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int ans = 2;
    test(nums, k, ans);
}

TEST(Q560, CASE2) {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int ans = 2;
    test(nums, k, ans);
}

TEST(Q560, CASE3) {
    vector<int> nums = {-1, -1, 1};
    int k = 0;
    int ans = 1;
    test(nums, k, ans);
}

TEST(Q560, CASE4) {
    vector<int> nums = {1, -1, 0};
    int k = 0;
    int ans = 3;
    test(nums, k, ans);
}