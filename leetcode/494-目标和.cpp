#include <vector>

#include "utils.h"

using namespace std;

int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if ((target + sum) % 2 != 0 || abs(target) > sum) return 0;
    target = (target + sum) / 2;
    vector<vector<int>> dp(target + 1, vector<int>(nums.size(), 0));
    dp[0][0] = 1;
    for (int i = 0; i < dp.size(); i++) {
        if (i == nums[0]) dp[i][0] += 1;
    }
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            if (i - nums[j] >= 0)
                dp[i][j] = dp[i - nums[j]][j - 1] + dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[target][nums.size() - 1];
}

void solution(vector<int> &nums, int target, int answer) {
    check(findTargetSumWays(nums, target), answer);
}

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {1, 1, 1, 1, 1};
    solution(nums, 3, 5);

    // case 2
    nums = {1};
    solution(nums, 1, 1);

    // case 3
    nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    solution(nums, 1, 256);
}