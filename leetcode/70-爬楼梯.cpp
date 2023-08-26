#include <vector>

#include "utils.h"

using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

void solution(int n, int target) { check(climbStairs(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(2, 2);

    // case 2
    solution(3, 3);
}