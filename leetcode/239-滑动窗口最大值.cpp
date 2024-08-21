#include <gtest/gtest.h>

#include <deque>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // 类似于优先队列的方法，但是是使用双端队列的形式实现的
        deque<int> maxQueue;
        for (int i = 0; i < k; ++i) {
            while (!maxQueue.empty() && nums[i] > maxQueue.back()) maxQueue.pop_back();
            maxQueue.push_back(nums[i]);
        }
        vector<int> rtn;
        for (int i = k; i < nums.size(); ++i) {
            rtn.push_back(maxQueue.front());
            if (nums[i - k] == maxQueue.front()) maxQueue.pop_front();
            while (!maxQueue.empty() && nums[i] > maxQueue.back()) maxQueue.pop_back();
            maxQueue.push_back((nums[i]));
        }
        rtn.push_back(maxQueue.front());
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

TEST(Q239, CASE3) {
    vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};
    int k = 4;
    vector<int> ans = {7, 7, 7, 7, 7};
    test(nums, k, ans);
}