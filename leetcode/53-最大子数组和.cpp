#include <gtest/gtest.h>

#include <climits>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};

void test(vector<int> &nums, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.maxSubArray(nums), ans);
}

TEST(Q53, CASE1) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = 6;
    test(nums, ans);
}

TEST(Q53, CASE2) {
    vector<int> nums = {1};
    int ans = 1;
    test(nums, ans);
}

TEST(Q53, CASE3) {
    vector<int> nums = {5, 4, -1, 7, 8};
    int ans = 23;
    test(nums, ans);
}

TEST(Q53, CASE4) {
    vector<int> nums = {-1};
    int ans = -1;
    test(nums, ans);
}