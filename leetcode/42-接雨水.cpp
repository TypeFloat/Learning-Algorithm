#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int> &height) {
        int sum = 0;
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        leftMax[0] = height[0];
        for (int i = 1; i < leftMax.size(); ++i) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        rightMax[rightMax.size() - 1] = height[height.size() - 1];
        for (int i = rightMax.size() - 2; i >= 0; --i) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        for (int i = 0; i < height.size(); ++i) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};

void test(vector<int> &height, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.trap(height), ans);
}

TEST(Q42, CASE1) {
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int ans = 9;
    test(height, ans);
}

TEST(Q42, CASE2) {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = 6;
    test(height, ans);
}

TEST(Q42, CASE3) {
    vector<int> height = {4, 2, 3};
    int ans = 1;
    test(height, ans);
}