#include <vector>

#include "utils.h"

using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = dp[0][1];
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[dp.size() - 1][4];
}

void solution(vector<int> &prices, int target) {
    check(maxProfit(prices), target);
}

int main(int argc, char **argv) {
    vector<int> prices;

    // case 1
    prices = {3, 3, 5, 0, 0, 3, 1, 4};
    solution(prices, 6);

    // case 2
    prices = {1, 2, 3, 4, 5};
    solution(prices, 4);

    // case 3
    prices = {7, 6, 4, 3, 1};
    solution(prices, 0);

    // case 4
    prices = {1};
    solution(prices, 0);
}