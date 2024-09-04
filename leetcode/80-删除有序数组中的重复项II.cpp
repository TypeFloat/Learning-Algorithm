#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 2, fast = 1;
        while (++fast < nums.size()) {
            if (nums[fast] == nums[slow - 1] && nums[fast] == nums[slow - 2])
                continue;
            nums[slow++] = nums[fast];
        }
        return slow;
    }
};

void test(vector<int> &nums, vector<int> &ans) {
    Solution solution = Solution();
    int length = solution.removeDuplicates(nums);
    vector<int> rtn = vector<int>(nums.begin(), nums.begin() + length);
    ASSERT_EQ(rtn, ans);
}

TEST(Q80, CASE1) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ans = {1, 1, 2, 2, 3};
    test(nums, ans);
}

TEST(Q80, CASE2) {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> ans = {0, 0, 1, 1, 2, 3, 3};
    test(nums, ans);
}