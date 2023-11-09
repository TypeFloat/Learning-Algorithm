#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> &nums, int target, int left, int right) {
    if (left > right) return -1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return nums[left] == target ? left : -1;
}
vector<int> searchRange(vector<int> &nums, int target) {
    // 寻找是否存在目标值，如果没有，直接结束
    int left = binary_search(nums, target, 0, nums.size() - 1);
    if (left == -1) return {-1, -1};
    int right = left;
    int index;
    // 寻找边界的过程就是在子区间内寻找目标值，若有，就修改边界，没有就结束寻找
    // 寻找左边界
    index = left - 1;
    while (index >= 0) {
        index = binary_search(nums, target, 0, index);
        if (index != -1) {
            left = index;
            --index;
        }
    }
    // 寻找右边界
    index = right + 1;
    while (index >= 0) {
        index = binary_search(nums, target, index, nums.size() - 1);
        if (index != -1) {
            right = index;
            ++index;
        }
    }
    return {left, right};
}

TEST(Q34, CASE1) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> outputs = {3, 4};
    ASSERT_EQ(searchRange(nums, 8), outputs);
}

TEST(Q34, CASE2) {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> outputs = {-1, -1};
    ASSERT_EQ(searchRange(nums, 6), outputs);
}

TEST(Q34, CASE3) {
    vector<int> nums = {};
    vector<int> outputs = {-1, -1};
    ASSERT_EQ(searchRange(nums, 0), outputs);
}

TEST(Q34, CASE4) {
    vector<int> nums = {1};
    vector<int> outputs = {0, 0};
    ASSERT_EQ(searchRange(nums, 1), outputs);
}