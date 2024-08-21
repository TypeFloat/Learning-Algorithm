#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 两数之和的思路是排序后双指针，三数之和的话加一个外循环，四数之和加两个外循环，以此类推
        // 需要注意的是，题目要求不可以包含重复的三元组，因此要注意去重的问题
        vector<vector<int>> rtn;
        int left, right, sum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            // 去重
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            left = i + 1, right = nums.size() - 1;
            sum = -nums[i];
            while (left < right) {
                if (sum == nums[left] + nums[right]) {
                    rtn.push_back({nums[i], nums[left], nums[right]});
                    // 去重，防止出现 {-4, 2, 2, 2, 2} 答案重复的情况
                    do {
                        ++left;
                    } while (left < right && nums[left] == nums[left - 1]);
                    do {
                        --right;
                    } while (left < right && nums[right] == nums[right] + 1);
                } else if (sum > nums[left] + nums[right]) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return rtn;
    }
};

bool cmp(vector<int> &numsA, vector<int> &numsB) {
    for (int i = 0; i < numsA.size(); ++i) {
        if (numsA[i] != numsB[i]) return numsA[i] < numsB[i];
    }
    return true;
}

void test(vector<int> &nums, vector<vector<int>> &ans) {
    Solution solution = Solution();
    vector<vector<int>> rtn = solution.threeSum(nums);
    ASSERT_EQ(rtn.size(), ans.size());
    for (int i = 0; i < rtn.size(); ++i) {
        sort(rtn[i].begin(), rtn[i].end(), [](int a, int b) { return a < b; });
        sort(ans[i].begin(), ans[i].end(), [](int a, int b) { return a < b; });
    }
    sort(rtn.begin(), rtn.end(), cmp);
    sort(ans.begin(), ans.end(), cmp);
    ASSERT_EQ(rtn, ans);
}

TEST(Q15, CASE1) {
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> ans = {{-1, -1, 2}, {-1, 0, 1}};
    test(nums, ans);
}

TEST(Q15, CASE2) {
    vector<int> nums = {0, 1, 1};
    vector<vector<int>> ans = {};
    test(nums, ans);
}

TEST(Q15, CASE3) {
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> ans = {{0, 0, 0}};
    test(nums, ans);
}

TEST(Q15, CASE4) {
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> ans = {{0, 0, 0}};
    test(nums, ans);
}

TEST(Q15, CASE5) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4, -1, 2};
    vector<vector<int>> ans = {{-4, 2, 2}, {-1, -1, 2}, {-1, 0, 1}};
    test(nums, ans);
}