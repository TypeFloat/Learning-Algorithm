#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int integerBreak(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 1;
        int maxVal;
        for (int i = 2; i < n; ++i) {
            maxVal = INT_MIN;
            for (int j = i - 1; j >= 0; --j) {
                maxVal = max(maxVal, dp[j] * (i - j));
                maxVal = max(maxVal, dp[j] * dp[i - j - 1]);
                maxVal = max(maxVal, (j + 1) * (i - j));
            }
            dp[i] = maxVal;
        }
        return dp[n - 1];
    }
};

void test(int n, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.integerBreak(n), ans);
}

TEST(Q343, CASE1) {
    int n = 10;
    int ans = 36;
    test(n, ans);
}