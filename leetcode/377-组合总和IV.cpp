#include <vector>

#include "utils.h"

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
        for (int num : nums) {
            if (i - num >= 0) dp[i] += (dp[i - num]);
        }
    }
    return dp[target];
}

void solution(vector<int>& nums, int target, int answer) {
    check(combinationSum4(nums, target), answer);
}

int main(int argc, char** argv) {
    vector<int> nums;

    // case 1
    nums = {1, 2, 3};
    solution(nums, 4, 7);

    // case 2
    nums = {0};
    solution(nums, 3, 0);
}