#include <vector>

#include "utils.h"

using namespace std;

int integerBreak(int n) {
    vector<int> dp(n + 1, 1);
    for (int i = 3; i < dp.size(); ++i) {
        for (int j = 1; j < i - 1; ++j) {
            dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
        }
    }
    return dp[n];
}

void solution(int n, int target) { check(integerBreak(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(2, 1);

    // case 2
    solution(10, 36);
}