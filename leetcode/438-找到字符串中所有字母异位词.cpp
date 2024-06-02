#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> rtn;
        vector<int> record(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            record[p[i] - 'a']++;
            record[s[i] - 'a']--;
        }
        int left = 0, right = p.size() - 1;
        while (true) {
            rtn.push_back(left);
            for (int i = 0; i < record.size(); ++i) {
                if (record[i] != 0) {
                    rtn.pop_back();
                    break;
                }
            }
            if (right + 1 == s.size()) break;
            record[s[left++] - 'a']++;
            record[s[++right] - 'a']--;
        }
        return rtn;
    }
};

void test(string &s, string &p, vector<int> &ans) {
    Solution solution = Solution();
    vector<int> rtn = solution.findAnagrams(s, p);
    sort(rtn.begin(), rtn.end(), [](int a, int b) { return a < b; });
    sort(ans.begin(), ans.end(), [](int a, int b) { return a < b; });
    ASSERT_EQ(rtn, ans);
}

TEST(Q438, CASE1) {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = {0, 6};
    test(s, p, ans);
}

TEST(Q438, CASE2) {
    string s = "abab";
    string p = "ab";
    vector<int> ans = {0, 1, 2};
    test(s, p, ans);
}

TEST(Q438, CASE3) {
    string s = "baa";
    string p = "aa";
    vector<int> ans = {1};
    test(s, p, ans);
}