#include <vector>

#include "utils.h"

using namespace std;

int rob(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] =
            dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
    }
    return dp[nums.size() - 1];
}

void solution(vector<int> &nums, int target) { check(rob(nums), target); }

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {1, 2, 3, 1};
    solution(nums, 4);

    // case 2
    nums = {2, 7, 9, 3, 1};
    solution(nums, 12);
}