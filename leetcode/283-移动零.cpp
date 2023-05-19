#include "utils.h"


void moveZeroes(vector<int>& nums)
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

int main(int argc, char **argv)
{
    vector<int> nums, target;

    // case 1
    nums = vector<int>{0, 1, 0, 3, 12};
    target = vector<int>{1, 3, 12, 0, 0};
    moveZeroes(nums);
    cout << "Case 1: " << check(target, nums) << endl;

    // case 2
    nums = vector<int>{0};
    target = vector<int>{0};
    moveZeroes(nums);
    cout << "Case 2: " << check(target, nums) << endl;
}