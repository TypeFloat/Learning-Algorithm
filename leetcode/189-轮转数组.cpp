#include <gtest/gtest.h>

#include <array>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<int> &nums, int k) {
        // 其实最好的方法是通过求解 nums.size() 和 k 的最大公约数来作为循环次数
        // 但是数学推导比较复杂，这里使用一个额外的变量count做交换元素的次数记录也可以
        int count = 0;
        int idx, nextIdx, tmp;
        int i = 0;
        while (count != nums.size()) {
            idx = i;
            tmp = nums[i];
            do {
                nextIdx = (idx + k) % nums.size();
                swap(nums[nextIdx], tmp);
                ++count;
                idx = nextIdx;
            } while (idx != i);
            ++i;
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