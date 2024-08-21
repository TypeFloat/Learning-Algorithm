#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        string sub;
        for (int i = 1; i <= s.size(); ++i) {
            for (string& word : wordDict) {
                if (dp[i]) break;
                if (i >= word.size() && dp[i - word.size()]) {
                    sub = s.substr(i - word.size(), word.size());
                    dp[i] = sub == word;
                }
            }
        }
        return dp[s.size()];
    }
};

void test(string &s, vector<string> &wordDict, bool ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.wordBreak(s, wordDict), ans);
}

TEST(Q139, CASE1) {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool ans = true;
    test(s, wordDict, ans);
}

TEST(Q139, CASE2) {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool ans = true;
    test(s, wordDict, ans);
}