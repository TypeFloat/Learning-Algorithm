#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // 使用滑动窗口维护字符串，并使用计数器记录滑动窗口内字符串的字母出现次数即可
        unordered_map<char, int> counter;
        int maxLength = 0;
        int left = 0, right = -1;
        while (++right < s.size()) {
            counter[s[right]]++;
            while (counter[s[right]] > 1) {
                counter[s[left++]]--;
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