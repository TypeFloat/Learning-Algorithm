#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(target - nums[i]) != record.end()) {
                return {record[target - nums[i]], i};
            }
            record[nums[i]] = i;
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