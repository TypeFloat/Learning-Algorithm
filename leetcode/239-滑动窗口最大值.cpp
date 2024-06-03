#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> maxQueue;
        vector<int> rtn;
        for (int i = 0; i < nums.size(); ++i) {
            // 删除窗口外的元素
            if (!maxQueue.empty() && maxQueue.front() <= i - k)
                maxQueue.pop_front();

            // 更新窗口内的元素
            if (maxQueue.empty()) {
                maxQueue.push_back(i);
            } else {
                while (!maxQueue.empty() && nums[i] > nums[maxQueue.back()]) {
                    maxQueue.pop_back();
                }
                maxQueue.push_back(i);
            }
            if (i >= k - 1) rtn.push_back(nums[maxQueue.front()]);
        }
        return rtn;
    }
};

void test(vector<int> &nums, int k, vector<int> &ans) {
    Solution solution = Solution();
    vector<int> rtn = solution.maxSlidingWindow(nums, k);
    ASSERT_EQ(rtn, ans);
}

TEST(Q239, CASE1) {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = {3, 3, 5, 5, 6, 7};
    test(nums, k, ans);
}

TEST(Q239, CASE2) {
    vector<int> nums = {1};
    int k = 1;
    vector<int> ans = {1};
    test(nums, k, ans);
}