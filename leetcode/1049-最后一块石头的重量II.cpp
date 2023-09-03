#include <vector>

#include "utils.h"

using namespace std;

int lastStoneWeightII(vector<int> &stones) {
    int sum = 0;
    for (int i = 0; i < stones.size(); ++i) {
        sum += stones[i];
    }
    int target = sum / 2;
    vector<vector<int>> dp(target + 1, vector<int>(stones.size(), 0));
    for (int i = 1; i < dp.size(); ++i) {
        if (i >= stones[0]) dp[i][0] = stones[0];
    }
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            if (i < stones[j])
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1] < dp[i - stones[j]][j - 1] + stones[j]
                               ? dp[i - stones[j]][j - 1] + stones[j]
                               : dp[i][j - 1];
        }
    }
    return sum - 2 * dp[target][stones.size() - 1];
}

void solution(vector<int> &stones, int target) {
    check(lastStoneWeightII(stones), target);
}

int main(int argc, char **argv) {
    vector<int> stones;

    // case 1
    stones = {2, 7, 4, 1, 8, 1};
    solution(stones, 1);

    // case 2
    stones = {31, 26, 33, 21, 40};
    solution(stones, 5);
}