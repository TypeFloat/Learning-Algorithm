#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size());
        dp[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); ++i) dp[i] = dp[i - 1] + grid[0][i];
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (j == 0)
                    dp[j] += grid[i][j];
                else
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[grid[0].size() - 1];
    }
};

void test(vector<vector<int>>& grid, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.minPathSum(grid), ans);
}

TEST(Q64, CASE1) {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans = 7;
    test(grid, ans);
}