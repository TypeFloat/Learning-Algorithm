#include <gtest/gtest.h>

#include <vector>

using namespace std;

bool judge(vector<int> &nums, int vel, int len) {
    for (int i = 0; i < len; ++i) {
        if (nums[i] == vel) return false;
    }
    return true;
}

int removeElement(vector<int> &nums, int vel) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        if (nums[left] == vel) {
            // 不需要进行交换，只需要覆盖即可
            // swap(nums[left], nums[right]);
            nums[left] = nums[right];
            --right;
        } else
            ++left;
    }
    return left;
}

TEST(Q27, CASE1) {
    vector<int> nums = {3, 2, 2, 3};
    ASSERT_EQ(removeElement(nums, 3), 2);
    ASSERT_TRUE(judge(nums, 3, 2));
}

TEST(Q27, CASE2) {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    ASSERT_EQ(removeElement(nums, 2), 5);
    ASSERT_TRUE(judge(nums, 2, 5));
}

TEST(Q27, CASE3) {
    vector<int> nums = {};
    ASSERT_EQ(removeElement(nums, 0), 0);
    ASSERT_TRUE(judge(nums, 0, 0));
}

TEST(Q27, CASE4) {
    vector<int> nums = {1};
    ASSERT_EQ(removeElement(nums, 1), 0);
    ASSERT_TRUE(judge(nums, 1, 0));
}