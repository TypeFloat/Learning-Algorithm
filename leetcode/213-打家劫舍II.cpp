#include <vector>

#include "utils.h"

using namespace std;

int rab(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for (int i = 2; i < dp.size() - 1; ++i) {
        dp[i] =
            dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
    }
    int max_val = dp[nums.size() - 2];
    dp[1] = nums[1];
    dp[2] = nums[2] > nums[1] ? nums[2] : nums[1];
    for (int i = 3; i < dp.size(); ++i) {
        dp[i] =
            dp[i - 2] + nums[i] > dp[i - 1] ? dp[i - 2] + nums[i] : dp[i - 1];
    }

    return dp[nums.size() - 1] > max_val ? dp[nums.size() - 1] : max_val;
}

void solution(vector<int> &nums, int target) { check(rab(nums), target); }

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {2, 3, 2};
    solution(nums, 3);

    // case 2
    nums = {1, 2, 3, 1};
    solution(nums, 4);

    // case 3
    nums = {1, 2, 3};
    solution(nums, 3);

    // case 4
    nums = {1, 2};
    solution(nums, 2);

    // case 5
    nums = {200, 3, 140, 20, 10};
    solution(nums, 340);
}