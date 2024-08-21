#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> rtn;
        vector<string> ans;
        string sub;
        backtrace(rtn, ans, s, sub, 0);
        return rtn;
    }

    void backtrace(vector<vector<string>> &rtn, vector<string> &ans, string &s,
                   string sub, int start) {
        if (start == s.size()) {
            if (sub == "") rtn.push_back(ans);
            return;
        }
        sub.push_back(s[start]);
        if (isPalindromic(sub)) {
            ans.push_back(sub);
            backtrace(rtn, ans, s, "", start + 1);
            ans.pop_back();
        }
        backtrace(rtn, ans, s, sub, start + 1);
        sub.pop_back();
    }

    bool isPalindromic(string &str) {
        if (str.size() == 0) return false;
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
};

void test(string &s, vector<vector<string>> &ans) {
    Solution solution = Solution();
    vector<vector<string>> rtn = solution.partition(s);
    ASSERT_EQ(rtn, ans);
}

TEST(Q131, CASE1) {
    string s = "aab";
    vector<vector<string>> ans = {{"a", "a", "b"}, {"aa", "b"}};
    test(s, ans);
}