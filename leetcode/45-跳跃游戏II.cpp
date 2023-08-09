#include <algorithm>
#include <vector>

#include "utils.h"

using namespace std;

int jump(vector<int> &nums) {
    if (nums.size() == 1) return 0;
    int count = 0;
    int max_cur = 0, max_next = 0;
    for (int i = 0; i < nums.size(); i++) {
        max_next = max(max_next, i + nums[i]);
        if (i == max_cur) {
            count++;
            max_cur = max_next;
            if (max_cur >= nums.size() - 1) break;
        }
    }
    return count;
}

void solution(vector<int> &nums, int target) { check(jump(nums), target); }

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {2, 3, 1, 1, 4};
    solution(nums, 2);

    // case 2
    nums = {2, 3, 0, 1, 4};
    solution(nums, 2);

    // case 3
    nums = {1, 2, 1, 1, 1};
    solution(nums, 3);

    // case 4
    nums = {0};
    solution(nums, 0);

    // case 5
    nums = {1};
    solution(nums, 0);

    // case 6
    nums = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    solution(nums, 2);
}