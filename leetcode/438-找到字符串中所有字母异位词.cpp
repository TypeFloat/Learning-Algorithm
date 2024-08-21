#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        // 思路不难，就是条件处理比较复杂，需要维护一个计数器，维护着“需要”的字符集字符个数
        if (p.size() > s.size()) return {};
        unordered_map<char, int> counter;
        int count = p.size();
        for (char ch : p) counter[ch]++;
        int left = 0, right = p.size() - 1;
        for (int i = left; i <= right; ++i) {
            if (counter.find(s[i]) != counter.end()) {
                counter[s[i]]--;
                if (counter[s[i]] >= 0) --count;
            }
        }
        vector<int> rtn;
        while (right < s.size() - 1) {
            if (count == 0) rtn.push_back(left);
            if (counter.find(s[left]) != counter.end()) {
                counter[s[left]]++;
                if (counter[s[left]] > 0) ++count;
            }
            ++left;
            ++right;
            if (counter.find(s[right]) != counter.end()) {
                counter[s[right]]--;
                if (counter[s[right]] >= 0) --count;
            }
        }
        if (count == 0) rtn.push_back(left);
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

TEST(Q438, CASE4) {
    string s = "bpaa";
    string p = "aa";
    vector<int> ans = {2};
    test(s, p, ans);
}

TEST(Q438, CASE5) {
    string s = "abacbabc";
    string p = "abc";
    vector<int> ans = {1, 2, 3, 5};
    test(s, p, ans);
}