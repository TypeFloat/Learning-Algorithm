#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int maxRange = nums[0], localRange, start = 1;
        int step = 1;
        while (maxRange < nums.size() - 1) {
            localRange = start + nums[start];
            for (int i = start; i <= maxRange; ++i) {
                localRange = max(localRange, i + nums[i]);
            }
            if (localRange > maxRange) {
                start = maxRange + 1;
                maxRange = localRange;
                ++step;
            }
        }
        return step;
    }
};

void test(vector<int>& nums, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.jump(nums), ans);
}

TEST(Q45, CASE1) {
    vector<int> nums = {1, 2, 1, 1, 1};
    int ans = 3;
    test(nums, ans);
}