#include <vector>

#include "utils.h"

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] >= 0) {
                if (dp[i] != -1)
                    dp[i] = dp[i - coin] + 1 > dp[i] ? dp[i] : dp[i - coin] + 1;
                else
                    dp[i] = dp[i - coin] + 1;
            }
        }
    }
    return dp[dp.size() - 1];
}

void solution(vector<int>& coins, int amount, int target) {
    check(coinChange(coins, amount), target);
}

int main(int argc, char** argv) {
    vector<int> coins;

    // case 1
    coins = {1, 2, 5};
    solution(coins, 11, 3);

    // case 2
    coins = {2};
    solution(coins, 3, -1);

    // case 3
    coins = {1};
    solution(coins, 0, 0);
}