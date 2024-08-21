#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool found;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                found = backtrace(board, visited, word, i, j, 0);
                if (found) return true;
            }
        }
        return false;
    }

    bool backtrace(vector<vector<char>> &board, vector<vector<bool>> &visited,
                   string &word, int x, int y, int tgt) {
        if (word[tgt] != board[x][y]) return false;
        ++tgt;
        if (tgt == word.size()) return true;
        bool found = false;
        int m = board.size(), n = board[0].size();
        visited[x][y] = true;
        if (!found && x - 1 >= 0 && !visited[x - 1][y])
            found = backtrace(board, visited, word, x - 1, y, tgt);
        if (!found && x + 1 < m && !visited[x + 1][y])
            found = backtrace(board, visited, word, x + 1, y, tgt);
        if (!found && y - 1 >= 0 && !visited[x][y - 1])
            found = backtrace(board, visited, word, x, y - 1, tgt);
        if (!found && y + 1 < n && !visited[x][y + 1])
            found = backtrace(board, visited, word, x, y + 1, tgt);
        visited[x][y] = false;
        return found;
    }
};

void test(vector<vector<char>> &board, string &word, bool ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.exist(board, word), ans);
}

TEST(Q79, CASE1) {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool ans = true;
    test(board, word, ans);
}