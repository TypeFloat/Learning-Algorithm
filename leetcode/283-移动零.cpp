#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        // 双指针，具体来说是快慢指针，慢指针指向0，快指针指向非零元素，然后交换
        // 有一个可以优化的点是，可以不执行交换，而是覆盖，这样可以减少操作的次数
        int slow = -1;
        while (++slow < nums.size() && nums[slow] != 0);
        int fast = slow + 1;
        while (fast < nums.size()) {
            if (nums[fast] != 0) nums[slow++] = nums[fast];
            ++fast;
        }
        for (int i = slow; i < nums.size(); ++i) nums[slow++] = 0;
    }
};

void test(vector<int> &nums, vector<int> &ans) {
    Solution solution = Solution();
    solution.moveZeroes(nums);
    ASSERT_EQ(nums, ans);
}

TEST(Q283, CASE1) {
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> ans = {1, 3, 12, 0, 0};
    test(nums, ans);
}

TEST(Q283, CASE2) {
    vector<int> nums = {0};
    vector<int> ans = {0};
    test(nums, ans);
}