#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int idx = 0, val;
        int times = nums.size();
        while (--times) {
            if (nums[idx] == idx + 1) {
                ++idx;
                continue;
            }
            val = nums[idx];
            nums[idx] = idx + 1;
            idx = val - 1;
        }
        return nums[nums.size() - 1];
    }
};

void test(vector<int>& nums, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.findDuplicate(nums), ans);
}

TEST(Q287, CASE1) {
    vector<int> nums = {1, 3, 4, 2, 2};
    int ans = 2;
    test(nums, ans);
}

TEST(Q287, CASE2) {
    vector<int> nums = {3, 1, 3, 4, 2};
    int ans = 2;
    test(nums, ans);
}