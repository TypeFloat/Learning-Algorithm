#include <vector>

#include "utils.h"

using namespace std;

bool canJump(vector<int> &nums) {
    int cover = 0;
    for (int i = 0; i <= cover; i++) {
        cover = max(cover, nums[i] + i);
        if (cover >= nums.size() - 1) return true;
    }
    return cover >= nums.size() - 1;
}

void solution(vector<int> &nums, bool target) { check(canJump(nums), target); }

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {2, 3, 1, 1, 4};
    solution(nums, true);

    // case 2
    nums = {3, 2, 1, 0, 4};
    solution(nums, false);

    // case 3
    nums = {0};
    solution(nums, true);

    // case 4
    nums = {3, 0, 8, 2, 0, 0, 1};
    solution(nums, true);

    // case 5
    nums = {5, 9, 3, 2, 1, 0, 2, 3, 1, 0, 0};
    solution(nums, true);
}