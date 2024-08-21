#include <gtest/gtest.h>

#include <climits>
#include <vector>

using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        // 具体的思想是让1出现的0号元素位置上，2出现在1号元素位置上，以此类推
        // 如果数组恰是1到n排列的，那经过上述排列后，数组就是有序的了，
        // 如果不是，那数组第k个元素应当不等于k+1
        // 无论是哪一种情况，再次遍历数组都可以得到答案
        int num;
        for (int i = 0; i < nums.size(); ++i) {
            num = nums[i];
            while (num > 0 && num - 1 < nums.size() && nums[num - 1] != num)
                swap(nums[num - 1], num);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};

void test(vector<int> &nums, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.firstMissingPositive(nums), ans);
}

TEST(Q41, CASE1) {
    vector<int> nums = {1, 2, 0};
    int ans = 3;
    test(nums, ans);
}

TEST(Q41, CASE2) {
    vector<int> nums = {3, 4, -1, 1};
    int ans = 2;
    test(nums, ans);
}

TEST(Q41, CASE3) {
    vector<int> nums = {7, 8, 9, 11, 12};
    int ans = 1;
    test(nums, ans);
}

TEST(Q41, CASE4) {
    vector<int> nums = {1, 1, 2, 3};
    int ans = 4;
    test(nums, ans);
}

TEST(Q41, CASE5) {
    vector<int> nums = {3, 1};
    int ans = 2;
    test(nums, ans);
}

TEST(Q41, CASE6) {
    vector<int> nums = {1};
    int ans = 2;
    test(nums, ans);
}

TEST(Q41, CASE7) {
    vector<int> nums = {2, 1};
    int ans = 3;
    test(nums, ans);
}