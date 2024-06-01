#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        int globalLeft = 1, globalRight = 0;
        for (int num : nums) {
            if (globalLeft <= num && num <= globalRight) continue;
            int left = num, right = num;
            while (record.find(right + 1) != record.end()) {
                right++;
                if (right >= globalLeft && right <= globalRight) {
                    right = globalRight;
                    break;
                }
            }
            if (right - left > globalRight - globalLeft) {
                globalLeft = left;
                globalRight = right;
            }
        }
        return globalRight - globalLeft + 1;
    };
};

void test(vector<int> &nums, int target) {
    Solution solution = Solution();
    ASSERT_EQ(solution.longestConsecutive(nums), target);
};

TEST(Q128, CASE1) {
    vector<int> nums = {100, 4, 200, 1, 2, 3};
    int target = 4;
    test(nums, target);
}

TEST(Q128, CASE2) {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int target = 9;
    test(nums, target);
}