#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int maxLength = 0;
        unordered_map<char, int> record;
        int left = 0, right = -1;
        char key;
        while (right < static_cast<int>(s.size()) - 1) {
            ++right;
            key = s[right];
            if (record.find(key) == record.end()) {
                record[key] = right;
            } else if (record[key] >= left) {
                left = record[key] + 1;
                record[key] = right;
            } else {
                record[key] = right;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

void test(string &s, int ans) {
    Solution solution = Solution();
    solution.lengthOfLongestSubstring(s);
    ASSERT_EQ(solution.lengthOfLongestSubstring(s), ans);
}

TEST(Q3, CASE1) {
    string s = "abcabcbb";
    int ans = 3;
    test(s, ans);
}

TEST(Q3, CASE2) {
    string s = "bbbbb";
    int ans = 1;
    test(s, ans);
}

TEST(Q3, CASE3) {
    string s = "pwwkew";
    int ans = 3;
    test(s, ans);
}

TEST(Q4, CASE4) {
    string s = "";
    int ans = 0;
    test(s, ans);
}

TEST(Q4, CASE5) {
    string s = "aabaab!bb";
    int ans = 3;
    test(s, ans);
}