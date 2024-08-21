#include <gtest/gtest.h>

#include <algorithm>
#include <ratio>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int> &height) {

    }
};

void test(vector<int> &height, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.maxArea(height), ans);
}

TEST(Q11, CASE1) {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = 49;
    test(height, ans);
}

TEST(Q11, CASE2) {
    vector<int> height = {1, 1};
    int ans = 1;
    test(height, ans);
}

TEST(Q11, CASE3) {
    vector<int> height = {1, 2, 1};
    int ans = 2;
    test(height, ans);
}