#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int minVal = INT_MAX;
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            minVal = min(minVal, nums[mid]);
            if (nums[mid] < nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return minVal;
    }
};

void test(vector<int>& nums, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.findMin(nums), ans);
}

TEST(Q153, CASE1) {
    vector<int> nums = {3, 4, 5, 1, 2};
    int ans = 1;
    test(nums, ans);
}