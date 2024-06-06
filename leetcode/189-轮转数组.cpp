#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<int> &nums, int k) {
        if (k == 0) return;
        int fromPtr, toPtr, fromVal, toVal;
        int startIdx = 0, count = 0;
        while (count < nums.size()) {
            fromPtr = startIdx;
            if (fromPtr >= nums.size()) break;
            fromVal = nums[fromPtr];
            do {
                toPtr = (fromPtr + k) % nums.size();
                toVal = nums[toPtr];
                nums[toPtr] = fromVal;
                fromVal = toVal;
                fromPtr = toPtr;
                ++count;

            } while (fromPtr != startIdx);
            ++startIdx;
        }
    }
};

void test(vector<int> &nums, int k, vector<int> &ans) {
    Solution solution = Solution();
    solution.rotate(nums, k);
    ASSERT_EQ(nums, ans);
}

TEST(Q189, CASE1) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    vector<int> ans = {5, 6, 7, 1, 2, 3, 4};
    test(nums, k, ans);
}

TEST(Q189, CASE2) {
    vector<int> nums = {-1, -100, 3, 99};
    int k = 2;
    vector<int> ans = {3, 99, -1, -100};
    test(nums, k, ans);
}

TEST(Q189, CASE3) {
    vector<int> nums = {-1, -100, 3, 99};
    int k = 0;
    vector<int> ans = {-1, -100, 3, 99};
    test(nums, k, ans);
}

TEST(Q189, CASE4) {
    vector<int> nums = {1};
    int k = 0;
    vector<int> ans = {1};
    test(nums, k, ans);
}

TEST(Q189, ÇASE5) {
    vector<int> nums = {1, 2, 3};
    int k = 2;
    vector<int> ans = {2, 3, 1};
    test(nums, k, ans);
}

TEST(Q189, CASE6) {
    vector<int> nums = {1, 2};
    int k = 1;
    vector<int> ans = {2, 1};
    test(nums, k, ans);
}

TEST(Q189, CASE7) {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 4;
    vector<int> ans = {3, 4, 5, 6, 1, 2};
    test(nums, k, ans);
}