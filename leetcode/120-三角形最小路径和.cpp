#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size() - 1].size(), 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0)
                    dp[j] = dp[j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    dp[j] = dp[j - 1] + triangle[i][j];
                else
                    dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        int minSum = INT_MAX;
        for (int i = 0; i < dp.size(); ++i)
            minSum = min(minSum, dp[i]);
        return minSum;
    }
};

void test(vector<vector<int>>& triangle, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.minimumTotal(triangle), ans);
}

TEST(Q120, CASE1) {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int ans = 11;
    test(triangle, ans);
}