#include <gtest/gtest.h>

#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    int low = 0, fast = 1;
    while (fast < nums.size()) {
        if (nums[low] != nums[fast]) nums[++low] = nums[fast];
        ++fast;
    }
    return low + 1;
}

void judge(vector<int> &nums, vector<int> &taget) {
    int length = removeDuplicates(nums);
    for (unsigned int i = 0; i < length; ++i) {
        ASSERT_EQ(nums[i], taget[i]);
    }
}

TEST(Q26, CASE1) {
    vector<int> nums{1, 1, 2}, target{1, 2};
    judge(nums, target);
}

TEST(Q26, CASE2) {
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, target{0, 1, 2, 3, 4};
    judge(nums, target);
}