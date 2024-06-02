#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> rtn;
        sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
        int left, right, sum;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    rtn.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    while (left < nums.size() && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    --right;
                    while (right >= 0 && nums[right] == nums[right + 1]) {
                        --right;
                    }
                } else if (sum < 0)
                    ++left;
                else
                    --right;
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