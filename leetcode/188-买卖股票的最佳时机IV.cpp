#include <vector>

#include "utils.h"

using namespace std;

int maxProfit(int k, vector<int> &prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(1 + 2 * k, 0));
    for (int i = 1; i < 2 * k; ++i) {
        if (i % 2 != 0) dp[0][i] = -prices[0];
    }
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j < 2 * k; j += 2) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
        }
    }
    return dp[dp.size() - 1][2 * k];
}

void solution(int k, vector<int> &prices, int target) {
    check(maxProfit(k, prices), target);
}

int main(int argc, char **argv) {
    vector<int> prices;

    // case 1
    prices = {2, 4, 1};
    solution(2, prices, 2);

    // case 2
    prices = {3, 2, 6, 5, 0, 3};
    solution(2, prices, 7);
}