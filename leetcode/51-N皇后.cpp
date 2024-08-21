#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rtn;
        vector<string> ans;
        vector<vector<bool>> hasQueue(n, vector<bool>(n, false));
        backtrace(rtn, ans, hasQueue, n);
        return rtn;
    }

    void backtrace(vector<vector<string>> &rtn, vector<string> &ans,
                   vector<vector<bool>> &hasQueue, int n) {
        if (ans.size() == n) {
            rtn.push_back(ans);
            return;
        }
        string str = "";
        for (int i = 0; i < n; ++i) {
            if (!validPos(ans.size(), i, hasQueue)) continue;
            str = string(n, '.');
            str[i] = 'Q';
            hasQueue[ans.size()][i] = true;
            ans.push_back(str);
            backtrace(rtn, ans, hasQueue, n);
            ans.pop_back();
            hasQueue[ans.size()][i] = false;
        }
    }

    bool validPos(int i, int j, vector<vector<bool>> hasQueue) {
        int x, y;
        for (x = 0; x < hasQueue.size(); ++x) {
            if (hasQueue[x][j]) return false;
        }
        for (y = 0; y < hasQueue.size(); ++y) {
            if (hasQueue[i][y]) return false;
        }
        x = i, y = j;
        while (--x >= 0 && --y >= 0) {
            if (hasQueue[x][y]) return false;
        }
        x = i, y = j;
        while (++x < hasQueue.size() && --y >= 0) {
            if (hasQueue[x][y]) return false;
        }
        x = i, y = j;
        while (--x >= 0 && ++y < hasQueue.size()) {
            if (hasQueue[x][y]) return false;
        }
        x = i, y = j;
        while (++x < hasQueue.size() && ++y < hasQueue.size()) {
            if (hasQueue[x][y]) return false;
        }
        return true;
    }
};

void test(int n, vector<vector<string>> &ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.solveNQueens(n), ans);
}

TEST(Q51, CASE1) {
    int n = 4;
    vector<vector<string>> ans = {
        {".Q..", "...Q", "Q...", "..Q."},
        {"..Q.", "Q...", "...Q", ".Q.."}};
    test(n, ans);
}