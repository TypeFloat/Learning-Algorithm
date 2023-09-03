#include <vector>

#include "utils.h"

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum % 2 != 0) return false;
    sum = sum / 2;
    vector<vector<int>> dp(sum + 1, vector<int>(nums.size(), 0));
    for (int i = 0; i < dp.size(); ++i) {
        if (i >= nums[0]) dp[i][0] = nums[0];
    }
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            if (i < nums[j]) {
                dp[i][j] = dp[i][j - 1];
            } else
                dp[i][j] = dp[i][j - 1] < dp[i - nums[j]][j - 1] + nums[j]
                               ? dp[i - nums[j]][j - 1] + nums[j]
                               : dp[i][j - 1];
        }
    }
    return dp[sum][nums.size() - 1] == sum;
}

void solution(vector<int>& nums, bool target) {
    check(canPartition(nums), target);
}

int main(int argc, char** argv) {
    vector<int> nums;

    // case 1
    nums = {1, 5, 11, 5};
    solution(nums, true);

    // case 2
    nums = {1, 2, 3, 5};
    solution(nums, false);
}