#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int rtn = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> island;
        pair<int, int> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                island.push(pair<int, int>(i, j));
                visited[i][j] = true;
                while (!island.empty()) {
                    pos = island.front();
                    island.pop();
                    // visited[pos.first][pos.second] = true;
                    if (pos.second - 1 >= 0 &&
                        grid[pos.first][pos.second - 1] == '1' &&
                        !visited[pos.first][pos.second - 1]) {
                        island.push(pair<int, int>(pos.first, pos.second - 1));
                        visited[pos.first][pos.second - 1] = true;
                    }
                    if (pos.second + 1 < n &&
                        grid[pos.first][pos.second + 1] == '1' &&
                        !visited[pos.first][pos.second + 1]) {
                        island.push(pair<int, int>(pos.first, pos.second + 1));
                        visited[pos.first][pos.second + 1] = true;
                    }
                    if (pos.first - 1 >= 0 &&
                        grid[pos.first - 1][pos.second] == '1' &&
                        !visited[pos.first - 1][pos.second]) {
                        island.push(pair<int, int>(pos.first - 1, pos.second));
                        visited[pos.first - 1][pos.second] = true;
                    }
                    if (pos.first + 1 < m &&
                        grid[pos.first + 1][pos.second] == '1' &&
                        !visited[pos.first + 1][pos.second]) {
                        island.push(pair<int, int>(pos.first + 1, pos.second));
                        visited[pos.first + 1][pos.second] = true;
                    }
                }
                ++rtn;
            }
        }
        return rtn;
    }
};

void test(vector<vector<char>>& grid, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.numIslands(grid), ans);
}

TEST(Q200, CASE1) {
    vector<vector<char>> grid = {
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '0', '1'},
        {'1', '1', '1', '0', '1'}
    };
    int ans = 1;
    test(grid, ans);
}