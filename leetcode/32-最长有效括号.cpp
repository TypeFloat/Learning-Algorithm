#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        int leftCount = 0;
        stack<char> myStack;
        int maxVal = 0;
        int sum;
        for (char ch : s) {
            if (ch == '(') {
                ++leftCount;
                myStack.push(ch);
            } else if (ch == ')') {
                if (leftCount == 0) {
                    maxVal = max<int>(maxVal, myStack.size());
                    while (!myStack.empty()) myStack.pop();
                } else {
                    sum = 1;
                    while (myStack.top() != '(') {
                        if (myStack.top() == '1') ++sum;
                        myStack.pop();
                    }
                    myStack.pop();
                    --leftCount;
                    for (int i = 0; i < sum; ++i) myStack.push('1');
                }
            }
        }
        sum = 0;
        while (!myStack.empty()) {
            if (myStack.top() == '1') ++sum;
            else {
                maxVal = max(maxVal, sum);
                sum = 0;
            }
            myStack.pop();
        }
        maxVal = max<int>(maxVal, sum);
        return 2 * maxVal;
    }
};

void test(string &s, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.longestValidParentheses(s), ans);
}

TEST(Q32, CASE1) {
    string s = "(()";
    int ans = 2;
    test(s, ans);
}

TEST(Q32, CASE2) {
    string s = ")()())";
    int ans = 4;
    test(s, ans);
}

TEST(Q32, CASE3) {
    string s = "";
    int ans = 0;
    test(s, ans);
}

TEST(Q32, CASE4) {
    string s = "()(()";
    int ans = 2;
    test(s, ans);
}

TEST(Q32, CASE5) {
    string s = "()";
    int ans = 2;
    test(s, ans);
}