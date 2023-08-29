#include <vector>

#include "utils.h"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(),
                           vector<int>(obstacleGrid[0].size(), 0));
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < obstacleGrid[0].size(); ++i) {
        if (obstacleGrid[0][i] == 1)
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i < obstacleGrid.size(); ++i) {
        if (obstacleGrid[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for (int i = 1; i < obstacleGrid.size(); ++i) {
        for (int j = 1; j < obstacleGrid[0].size(); ++j) {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}

void solution(vector<vector<int>>& obstacleGrid, int target) {
    check(uniquePathsWithObstacles(obstacleGrid), target);
}

int main(int argc, char** argv) {
    vector<vector<int>> obstacleGrid;

    // case 1
    obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    solution(obstacleGrid, 2);

    // case 2
    obstacleGrid = {{0, 1}, {0, 0}};
    solution(obstacleGrid, 1);
}