#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> singleStack;
        vector<int> rtn(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!(singleStack.empty() ||
                     temperatures[i] <= temperatures[singleStack.top()])) {
                rtn[singleStack.top()] = i - singleStack.top();
                singleStack.pop();
            }
            singleStack.push(i);
        }
        while (!singleStack.empty()) {
            rtn[singleStack.top()] = 0;
            singleStack.pop();
        }
        return rtn;
    }
};

void test(vector<int> &temperatures, vector<int> &ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.dailyTemperatures(temperatures), ans);
}

TEST(Q739, CASE1) {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = {1, 1, 4, 2, 1, 1, 0, 0};
}