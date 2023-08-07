#include <climits>
#include <vector>

#include "utils.h"

using namespace std;

int maxSubArray(vector<int> &nums) {
    int max_val = INT_MIN;
    int tmp_val = 0;
    for (int num : nums) {
        tmp_val += num;
        if (tmp_val > max_val) max_val = tmp_val;
        if (tmp_val < 0) tmp_val = 0;
    }
    return max_val;
}

void solution(vector<int> &nums, int target) {
    check(maxSubArray(nums), target);
}

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    solution(nums, 6);

    // case 2
    nums = {1};
    solution(nums, 1);

    // case 3
    nums = {5, 4, -1, 7, 8};
    solution(nums, 23);
}