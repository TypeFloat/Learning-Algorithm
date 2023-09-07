#include <vector>

#include "utils.h"

using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (dp[i] == 0)
                dp[i] = dp[i - j * j] + 1;
            else
                dp[i] = dp[i - j * j] + 1 > dp[i] ? dp[i] : dp[i - j * j] + 1;
        }
    }
    return dp[n];
}

void solution(int n, int target) { check(numSquares(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(12, 3);

    // case 2
    solution(13, 2);
}