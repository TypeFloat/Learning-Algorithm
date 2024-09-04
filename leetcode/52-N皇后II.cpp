#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
   public:
    int totalNQueens(int n) {
        int rtn = 0;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        backtrace(board, rtn, 0, n);
        return rtn;
    }

    void backtrace(vector<vector<bool>> &board, int &rtn, int lane, int n) {
        if (lane == n) {
            ++rtn;
            return;
        }
        bool isValid;
        int j, k;
        for (int i = 0; i < n; ++i) {
            isValid = true;
            // 列
            for (j = 0; j < n; ++j) {
                if (board[j][i]) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) continue;

            // 右上
            j = lane - 1;
            k = i + 1;
            while (j >= 0 && k < n) {
                if (board[j--][k++]) {
                    isValid = false;
                    break;
                }
            }
            // 左上
            j = lane - 1;
            k = i - 1;
            while (j >= 0 && k >= 0) {
                if (board[j--][k--]) {
                    isValid = false;
                    break;
                }
            }
            // 右下
            j = lane + 1;
            k = i + 1;
            while (j < n && k < n) {
                if (board[j++][k++]) {
                    isValid = false;
                    break;
                }
            }
            // 左下
            j = lane + 1;
            k = i - 1;
            while (j < n && k >= 0) {
                if (board[j++][k--]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                board[lane][i] = true;
                backtrace(board, rtn, lane + 1, n);
                board[lane][i] = false;
            }
        }
    }
};

void test(int n, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.totalNQueens(n), ans);
}

TEST(Q52, CASE1) {
    int n = 4;
    int ans = 2;
    test(n, ans);
}