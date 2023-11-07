#include <gtest/gtest.h>

#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return nums[left] >= target ? left : left + 1;
}

TEST(Q35, CASE1) {
    vector<int> nums = {1, 3, 5, 6};
    ASSERT_EQ(searchInsert(nums, 5), 2);
}

TEST(Q35, CASE2) {
    vector<int> nums = {1, 3, 5, 6};
    ASSERT_EQ(searchInsert(nums, 2), 1);
}

TEST(Q35, CASE3) {
    vector<int> nums = {1, 3, 5, 6};
    ASSERT_EQ(searchInsert(nums, 7), 4);
}

TEST(Q35, CASE4) {
    vector<int> nums = {1, 3};
    ASSERT_EQ(searchInsert(nums, 2), 1);
}