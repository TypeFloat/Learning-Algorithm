#include <vector>

#include "utils.h"

using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[i - j] * dp[j - 1];
        }
    }
    return dp[n];
}

void solution(int n, int target) { check(numTrees(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(3, 5);

    // case 2
    solution(1, 1);
}