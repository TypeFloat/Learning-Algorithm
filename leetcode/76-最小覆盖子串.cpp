#include <gtest/gtest.h>

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> record;
        for (char ch : t) {
            if (record.find(ch) != record.end())
                record[ch]++;
            else
                record[ch] = 1;
        }
        int minLeft = 0, minRight = s.size(), left = 0, right = -1;
        bool isExpand = true;
        while (right < static_cast<int>(s.size())) {
            if (isExpand) {
                ++right;
                if (record.find(s[right]) != record.end()) {
                    record[s[right]]--;
                    if (right - left + 1 >= t.size() && record[s[right]] == 0 &&
                        this->include(record)) {
                        isExpand = !isExpand;
                        if (right - left < minRight - minLeft) {
                            minRight = right;
                            minLeft = left;
                        }
                    }
                }
            } else {
                ++left;
                if (record.find(s[left - 1]) != record.end()) {
                    record[s[left - 1]]++;
                    if (record[s[left - 1]] > 0) {
                        isExpand = !isExpand;
                    }
                }
                if (!isExpand && minRight - minLeft > right - left) {
                    minLeft = left;
                    minRight = right;
                }
            }
        }
        if (minRight == s.size())
            return "";
        else
            return string(s.begin() + minLeft, s.begin() + minRight + 1);
    }

    bool include(unordered_map<char, int> &record) {
        bool flag = true;
        for (auto [key, value] : record) {
            if (value > 0) {
                flag = false;
                break;
            }
        }
        return flag;
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