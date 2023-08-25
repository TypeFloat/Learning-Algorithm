#include <array>
#include <vector>

#include "utils.h"

using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    array<int, 2> dp = {0, 1};
    for (int i = 2; i <= n; ++i) {
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return dp[1];
}

void solution(int n, int target) { check(fib(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(2, 1);

    // case 2
    solution(3, 2);

    // case 3
    solution(4, 3);
}