#include <vector>

#include "utils.h"

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    vector<int> dp(cost.size(), 0);
    for (int i = 2; i < cost.size(); ++i) {
        dp[i] = cost[i - 2] + dp[i - 2] > cost[i - 1] + dp[i - 1]
                    ? cost[i - 1] + dp[i - 1]
                    : cost[i - 2] + dp[i - 2];
    }
    return dp[dp.size() - 1];
}

void solution(vector<int>& cost, int target) {
    check(minCostClimbingStairs(cost), target);
}

int main(int argc, char** argv) {
    vector<int> cost;

    // case 1
    cost = {10, 15, 20};
    solution(cost, 15);

    // case 2
    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    solution(cost, 6);
}