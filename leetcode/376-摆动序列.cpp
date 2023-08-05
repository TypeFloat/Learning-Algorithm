#include <climits>
#include <vector>

#include "utils.h"

using namespace std;

int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() <= 1) return nums.size();
    int index = 1;
    while (index < nums.size() && nums[index] == nums[index - 1]) index++;
    if (index == nums.size()) return 1;
    bool isUp;
    int peak_val = nums[index - 1];
    if (nums[index] >= nums[index - 1])
        isUp = true;
    else
        isUp = false;
    int count = 1;
    for (auto num = nums.begin() + index; num != nums.end(); ++num) {
        if (isUp) {
            if (*num < *(num - 1)) {
                count++;
                isUp = false;
                peak_val = *(num - 1);
            }
        } else {
            if (*num > *(num - 1)) {
                count++;
                isUp = true;
                peak_val = *(num - 1);
            }
        }
    }
    if ((isUp && nums[nums.size() - 1] > peak_val) ||
        (!isUp && nums[nums.size() - 1] < peak_val))
        count++;
    return count;
}

void solution(vector<int> &nums, int target) {
    check(wiggleMaxLength(nums), target);
}

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {1, 7, 4, 9, 2, 5};
    solution(nums, 6);

    // case 2
    nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    solution(nums, 7);

    // case 3
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    solution(nums, 2);

    // case 4
    nums = {3, 3, 3, 2, 5};
    solution(nums, 3);
}