#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};

void test(string &text1, string &text2, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.longestCommonSubsequence(text1, text2), ans);
}

TEST(Q1143, CASE1) {
    string text1 = "abcde";
    string text2 = "ace";
    int ans = 3;
    test(text1, text2, ans);
}