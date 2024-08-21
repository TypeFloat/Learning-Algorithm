#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 因为数组是无序的，使用双指针需要保证数组有序，需要进行排序
        // 而题目又要求返回原始下标，因此需要额外的数据结构进行保存
        vector<vector<int>> numsWithOrder(nums.size(), vector<int>(2, 0));
        for (int i = 0; i < nums.size(); ++i) {
            numsWithOrder[i][0] = nums[i];
            numsWithOrder[i][1] = i;
        }
        sort(numsWithOrder.begin(), numsWithOrder.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[0] < b[0];
        });
        // 双指针，向内靠近
        int left = 0, right = nums.size() - 1, sum;
        // 数组中同一元素不能重复出现，所以left!=right
        while (left < right) {
            sum = numsWithOrder[left][0] + numsWithOrder[right][0];
            if (sum == target) return {numsWithOrder[left][1], numsWithOrder[right][1]};
            else if (sum > target)
                --right;
            else ++left;
        }
        return {};
    }
};

void test(vector<int> &nums, vector<int> &ans, int target) {
    Solution solution = Solution();
    vector<int> rtn = solution.twoSum(nums, target);
    sort(rtn.begin(), rtn.end(), [](int a, int b) { return a < b; });
    sort(ans.begin(), ans.end(), [](int a, int b) { return a < b; });
    ASSERT_EQ(rtn, ans);
}

TEST(Q1, CASE1) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = {0, 1};
    test(nums, ans, target);
}

TEST(Q1, CASE2) {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> ans = {1, 2};
    test(nums, ans, target);
}

TEST(Q1, CASE3) {
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> ans = {0, 1};
    test(nums, ans, target);
}