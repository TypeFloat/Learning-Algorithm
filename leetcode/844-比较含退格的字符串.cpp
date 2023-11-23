#include <gtest/gtest.h>

#include <cstddef>
#include <stack>

using namespace std;

// bool backspaceCompare(string s, string t) {
//     stack<char> s_stack, t_stack;
//     for (char ch : s) {
//         if (ch == '#') {
//             if (!s_stack.empty()) s_stack.pop();
//         } else
//             s_stack.push(ch);
//     }
//     for (char ch : t) {
//         if (ch == '#') {
//             if (!t_stack.empty()) t_stack.pop();
//         } else
//             t_stack.push(ch);
//     }
//     if (s_stack.size() != t_stack.size()) return false;
//     while (!s_stack.empty()) {
//         char ch_s = s_stack.top(), ch_t = t_stack.top();
//         if (ch_s != ch_t) return false;
//         s_stack.pop();
//         t_stack.pop();
//     }
//     return true;
// }

bool backspaceCompare(string s, string t) {
    int s_point = static_cast<int>(s.size()) - 1;
    int t_point = static_cast<int>(t.size()) - 1;
    int s_skip = 0;
    int t_skip = 0;
    while (s_point >= 0 || t_point >= 0) {
        while (s_point >= 0) {
            if (s[s_point] == '#') {
                ++s_skip;
                --s_point;
            } else if (s_skip > 0) {
                --s_skip;
                --s_point;
            } else {
                break;
            }
        }
        while (t_point >= 0) {
            if (t[t_point] == '#') {
                ++t_skip;
                --t_point;
            } else if (t_skip > 0) {
                --t_skip;
                --t_point;
            } else {
                break;
            }
        }
        if (s_point >= 0 && t_point >= 0) {
            if (s[s_point] != t[t_point]) {
                return false;
            }
        } else {
            if (s_point >= 0 || t_point >= 0) {
                return false;
            }
        }
        --s_point;
        --t_point;
    }
    return true;
}

TEST(Q844, CASE1) {
    string s = "ab#c", t = "ad#c";
    ASSERT_EQ(backspaceCompare(s, t), true);
}

TEST(Q844, CASE2) {
    string s = "ab##", t = "c#d#";
    ASSERT_EQ(backspaceCompare(s, t), true);
}

TEST(Q844, CASE3) {
    string s = "a#c", t = "b";
    ASSERT_EQ(backspaceCompare(s, t), false);
}

TEST(Q844, CASE4) {
    string s = "y#fo##f", t = "y#f#o##f";
    ASSERT_EQ(backspaceCompare(s, t), true);
}

TEST(Q844, CASE5) {
    string s = "abcd", t = "bbcd";
    ASSERT_EQ(backspaceCompare(s, t), false);
}

TEST(Q844, CASE6) {
    string s = "bxj##tw", t = "bxj###tw";
    ASSERT_EQ(backspaceCompare(s, t), false);
}

TEST(Q844, CASE7) {
    string s = "nzp#o#g", t = "b#nzp#o#g";
    ASSERT_EQ(backspaceCompare(s, t), true);
}