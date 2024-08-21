#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int length = 1;
        string rtn = string(s.begin(), s.begin() + 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) dp[i][j] = true;
                else if (j == i + 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j] && j - i + 1 > length) {
                    length = j - i + 1;
                    rtn = string(s.begin() + i, s.begin() + j + 1);
                }
            }
        }
        return rtn;
    }
};

void test(string &s, string &ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.longestPalindrome(s), ans);
}

TEST(Q5, CASE1) {
    string s = "aaaa";
    string ans = "aaaa";
    test(s, ans);
}