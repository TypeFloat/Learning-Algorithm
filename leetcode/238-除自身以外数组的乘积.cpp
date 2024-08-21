#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // 前向和向后两次循环，向前循环时计算前缀积，向后时计算后缀积
        // 但是因为这个后缀积不需要在别的地方使用了，因此得到最终计算结果之后抛弃就可以了，所以后缀积只使用一个常数进行存储，而不是数组
        // 因为借用了返回值的数组进行记录，没有使用其他的存储空间
        // 所以空间复杂度仍是常数级的
        vector<int> rtn = vector<int>(nums.size(), 0);
        rtn[1] = nums[0];
        for (int i = 2; i < nums.size(); ++i) rtn[i] = nums[i - 1] * rtn[i - 1];
        int res = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i > 0; --i) {
            rtn[i] = rtn[i] * res;
            res *= nums[i];
        }
        rtn[0] = res;
        return rtn;
    }
};

void test(vector<int> &nums, vector<int> &ans) {
    Solution solution = Solution();
    vector<int> rtn = solution.productExceptSelf(nums);
    ASSERT_EQ(rtn, ans);
}

TEST(Q238, CASE1) {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = {24, 12, 8, 6};
    test(nums, ans);
}

TEST(Q238, CASE2) {
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> ans = {0, 0, 9, 0, 0};
    test(nums, ans);
}