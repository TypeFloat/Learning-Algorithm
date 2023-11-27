#include <gtest/gtest.h>

#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";
    unordered_map<char, int> dict, window;
    for (char ch : t) {
        if (dict.find(ch) != dict.end())
            dict[ch] += 1;
        else
            dict[ch] = 1;
    }

    int left = 0, min_left = 0, min_right = s.size();
    for (int i = 0; i < s.size(); ++i) {
        // 元素位于字典中，可能会改变当前窗口
        if (dict.find(s[i]) != dict.end()) {
            dict[s[i]] -= 1;
            // 检查是否已经满足题目要求
            // 如果大于0，明显不符合题目条件
            // 如果小于0，说明对应的字母早已满足条件，不需要重复检查
            if (dict[s[i]] <= 0) {
                bool check = true;
                for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
                    if (iter->second > 0) {
                        check = false;
                        break;
                    }
                }
                // 如果已经满足，开始缩小窗口
                if (check) {
                    while (check) {
                        if (dict.find(s[left]) != dict.end()) {
                            // 窗口已无法缩小
                            if (dict[s[left]] == 0)
                                check = false;
                            else
                                dict[s[left++]] += 1;
                        } else
                            ++left;
                    }
                    // 更新最小窗口长度
                    if (i - left < min_right - min_left) {
                        min_left = left;
                        min_right = i;
                    }
                }
            }
        }
    }
    if (min_right != s.size())
        return string(s.begin() + min_left, s.begin() + min_right + 1);
    else
        return "";
}

TEST(Q76, CASE1) {
    string s = "ADOBECODEBANC", t = "ABC", target = "BANC";
    ASSERT_EQ(minWindow(s, t), target);
}

TEST(Q76, CASE2) {
    string s = "a", t = "a", target = "a";
    ASSERT_EQ(minWindow(s, t), target);
}

TEST(Q76, CASE3) {
    string s = "a", t = "aa", target = "";
    ASSERT_EQ(minWindow(s, t), target);
}