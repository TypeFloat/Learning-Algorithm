#include <gtest/gtest.h>

#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string decodeString(string s) {
        string rtn = "";
        stack<string> commands;
        string num, sub, tmp;
        int depth = 0;
        for (char ch : s) {
            if (ch == '[') {
                ++depth;
                sub = "";
                sub += ch;
                commands.push(sub);
            } else if (ch == ']') {
                sub = commands.top();
                commands.pop();
                commands.pop();
                num = commands.top();
                commands.pop();
                --depth;
                for (int i = 0; i < stoi(num); ++i) tmp += sub;
                if (depth == 0)
                    rtn += tmp;
                else
                    if (commands.top()[0] == '[') commands.push(tmp);
                    else commands.top() += tmp;
                tmp = "";
            } else if (isDigit(ch)) {
                if (commands.empty() || !isDigit(commands.top()[0])) {
                    sub = "";
                    sub += ch;
                    commands.push(sub);
                } else
                    commands.top() += ch;
            } else {
                if (commands.empty())
                    rtn += ch;
                else if (commands.top()[0] == '[') {
                    sub = "";
                    sub += ch;
                    commands.push(sub);
                } else
                    commands.top() += ch;
            }
        }
        return rtn;
    }

    bool isDigit(char ch) {
        return ch - '0' > 9 || ch - '0' < 0 ? false : true;
    }
};

void test(string &s, string &ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.decodeString(s), ans);
}

TEST(Q394, CASE1) {
    string s = "3[a]2[bc]";
    string ans = "aaabcbc";
    test(s, ans);
}

TEST(Q394, CASE2) {
    string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string ans =
        "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
    test(s, ans);
}