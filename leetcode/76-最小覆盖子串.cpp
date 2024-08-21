#include <gtest/gtest.h>

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> counter;
        for (char ch : t) counter[ch]++;
        int count = t.size();
        int left = 0, right = -1;
        int minLeft = 0, minRight = s.size();
        while (++right < s.size()) {
            if (counter.find(s[right]) != counter.end()) {
                if (--counter[s[right]] >= 0) --count;
            }
            while (left < s.size() && count == 0) {
                if (right - left < minRight - minLeft) {
                    minLeft = left;
                    minRight = right;
                }
                if (counter.find(s[left]) != counter.end()) {
                    ++counter[s[left]];
                    if (counter[s[left]] > 0) ++count;
                }
                ++left;
            }
        }
        return minRight == s.size() ? "" : s.substr(minLeft, minRight - minLeft + 1);
    }
};

void test(string &s, string &t, string &ans) {
    Solution solution = Solution();
    string rtn = solution.minWindow(s, t);
    ASSERT_EQ(rtn, ans);
}

TEST(Q76, CASE1) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = "BANC";
    test(s, t, ans);
}

TEST(Q76, CASE2) {
    string s = "a";
    string t = "a";
    string ans = "a";
    test(s, t, ans);
}

TEST(Q76, CASE3) {
    string s = "a";
    string t = "tt";
    string ans = "";
    test(s, t, ans);
}

TEST(Q76, CASE4) {
    string s = "a";
    string t = "b";
    string ans = "";
    test(s, t, ans);
}