#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> record;
        record[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            if (record.find(sum - k) != record.end()) {
                count += record[sum - k];
            }
            if (record.find(sum) != record.end()) {
                record[sum]++;
            } else {
                record[sum] = 1;
            }
        }
        return count;
    }
};

void test(vector<int> &nums, int k, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.subarraySum(nums, k), ans);
}

TEST(Q560, CASE1) {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int ans = 2;
    test(nums, k, ans);
}

TEST(Q560, CASE2) {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int ans = 2;
    test(nums, k, ans);
}

TEST(Q560, CASE3) {
    vector<int> nums = {-1, -1, 1};
    int k = 0;
    int ans = 1;
    test(nums, k, ans);
}