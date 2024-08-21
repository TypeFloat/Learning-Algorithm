#include <gtest/gtest.h>

#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
   public:
    int trap(vector<int> &height) {
        int maxHeight;
        vector<int> water(height.size(), INT_MAX);
        maxHeight = 0;
        for (int i = 0; i < height.size(); ++i) {
            maxHeight = max(maxHeight, height[i]);
            water[i] = min(water[i], maxHeight - height[i]);
        }
        maxHeight = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            maxHeight = max(maxHeight, height[i]);
            water[i] = min(water[i], maxHeight - height[i]);
        }
        return accumulate(water.begin(), water.end(), 0);
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