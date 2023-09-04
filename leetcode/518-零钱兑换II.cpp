#include <vector>

#include "utils.h"

using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = 1; i < dp.size(); ++i) {
            if (i >= coin) {
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[amount];
}

void solution(int amount, vector<int>& coins, int target) {
    check(change(amount, coins), target);
}

int main(int argc, char** argv) {
    vector<int> coins;

    // case 1
    coins = {1, 2, 5};
    solution(5, coins, 4);

    // case 2
    coins = {2};
    solution(3, coins, 0);

    // case 3
    coins = {10};
    solution(10, coins, 1);
}