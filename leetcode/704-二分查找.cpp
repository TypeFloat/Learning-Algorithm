#include <gtest/gtest.h>

using namespace std;

int search(vector<int> &nums, int target) {
    // 不能用 unsigned int，因为 right 可能会小于 0
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
        // 等同于 mid = (left + right) / 2，这样可以防止 left + right 数据溢出
        mid = (right - left) / 2 + left;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

TEST(TEST704, CASE1) {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    ASSERT_EQ(search(nums, target), 4);
}

TEST(TEST704, CASE2) {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;
    ASSERT_EQ(search(nums, target), -1);
}