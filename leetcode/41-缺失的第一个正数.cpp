#include <gtest/gtest.h>

#include <climits>
#include <vector>

using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0 || nums[i] > nums.size())
                continue;
            else
                while (nums[i] > 0 && nums[i] <= nums.size() &&
                       i != nums[i] - 1 && nums[i] != nums[nums[i] - 1]) {
                    swap(nums[i], nums[nums[i] - 1]);
                };
        }
        int ptr = 0;
        for (ptr = 0; ptr < nums.size(); ++ptr) {
            if (nums[ptr] != ptr + 1) break;
        }
        return ptr + 1;
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