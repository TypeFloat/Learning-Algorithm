#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int> &nums, int k) {
        // 考察大根堆的使用，使用大根堆进行排序时是顺序的，因此第K大元素出现在倒数第K个位置上
        // 一定掌握堆排序的使用
        buildMaxHeap(nums);
        for (int i = 0; i < k; ++i) {
            swap(nums[0], nums[nums.size() - 1 - i]);
            changeMaxHeap(nums, 0, nums.size() - 1 - i);
        }
        return nums[nums.size() - k];
    }

    void buildMaxHeap(vector<int> &nums) {
        int swapedId, left, right, root;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (i % 2 == 0) continue;
            left = i;
            right = i + 1;
            root = right / 2 - 1;
            if (right < nums.size() && nums[left] < nums[right])
                swapedId = right;
            else
                swapedId = left;
            if (nums[root] < nums[swapedId]) {
                swap(nums[root], nums[swapedId]);
                changeMaxHeap(nums, swapedId, nums.size());
            }
        }
    }

    void changeMaxHeap(vector<int> &nums, int idx, int range) {
        if (idx >= range || 2 * idx + 1 >= range) return;
        int swapedId;
        if (2 * idx + 2 < range && nums[2 * idx + 2] > nums[2 * idx + 1])
            swapedId = 2 * idx + 2;
        else
            swapedId = 2 * idx + 1;
        if (nums[idx] < nums[swapedId]) {
            swap(nums[idx], nums[swapedId]);
            changeMaxHeap(nums, swapedId, range);
        }
    }
};

void test(vector<int> &nums, int k, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.findKthLargest(nums, k), ans);
}

TEST(Q215, CASE1) {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int ans = 5;
    test(nums, k, ans);
}

TEST(Q215, CASE2) {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    int ans = 4;
    test(nums, k, ans);
}