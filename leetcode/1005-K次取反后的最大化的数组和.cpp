#include <ratio>
#include <vector>

#include "utils.h"

using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int index = 0;
    while (k > 0) {
        if (nums[index] < 0) {
            nums[index] *= -1;
            if (index < nums.size() - 1) index++;
        } else {
            if (k % 2 != 0) {
                if (index >= 1)
                    index = nums[index] > nums[index - 1] ? index - 1 : index;
                else
                    index = 0;
                nums[index] *= -1;
            }
            k = 0;
        }
        k--;
    }
    for (int i = 0; i < nums.size(); ++i) count += nums[i];
    return count;
}

void solution(vector<int> &nums, int k, int target) {
    check(target, largestSumAfterKNegations(nums, k));
}

int main(int argc, char **argv) {
    vector<int> nums;

    // case 1
    nums = {4, 2, 3};
    solution(nums, 1, 5);

    // case 2
    nums = {3, -1, 0, 2};
    solution(nums, 3, 6);

    // case 3
    nums = {2, -3, -1, 5, -4};
    solution(nums, 2, 13);

    // case 4
    nums = {5, 6, 9, -3, 3};
    solution(nums, 2, 20);

    // case 5
    nums = {-8, 3, -5, -3, -5, -2};
    solution(nums, 6, 22);

    // case 6
    nums = {-4, -2, -3};
    solution(nums, 4, 9);
}