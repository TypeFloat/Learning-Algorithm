#include "utils.h"

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int slow = 0, fast = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != 0)
        {
            nums[slow++] = nums[fast];
        }
        ++fast;
    }
    // 移动0，可以通过将后面的值赋0来实现，这样可以减少移动次数
    while (slow < nums.size())
    {
        nums[slow++] = 0;
    }
}

void solution(vector<int> &nums, vector<int> &target)
{
    moveZeroes(nums);
    check(target, nums);
}

int main(int argc, char **argv)
{
    vector<int> nums, target;

    // case 1
    nums = {0, 1, 0, 3, 12};
    target = {1, 3, 12, 0, 0};
    solution(nums, target);

    // case 2
    nums = {0};
    target = {0};
    solution(nums, target);
}