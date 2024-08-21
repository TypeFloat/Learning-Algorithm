#include <gtest/gtest.h>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            cout << mid << endl;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                if (nums[left] < nums[mid] || nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (nums[right] > nums[mid] || nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};

void test(vector<int>& nums, int target, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.search(nums, target), ans);
}

TEST(Q33, CASE1) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = 4;
    test(nums, target, ans);
}