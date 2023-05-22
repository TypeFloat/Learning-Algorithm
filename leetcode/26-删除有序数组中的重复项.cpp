#include "utils.h"


int removeDuplicates(vector<int>& nums)
{
    int slow = 0, fast = 1;
    while (fast < nums.size())
    {
        if (nums[slow] != nums[fast])
        {
            ++slow;
            nums[slow] = nums[fast];
        }
        ++fast;
    }
    return slow + 1;
}

int main(int argc, char **argv)
{
    vector<int> nums, target;

    // case1
    nums = vector<int>{1, 1, 2};
    target = vector<int>{1, 2};
    check(vector<int>(nums.begin(), nums.begin()+removeDuplicates(nums)), target);

    // case2
    nums = vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    target = vector<int>{0, 1, 2, 3, 4};
    check(vector<int>(nums.begin(), nums.begin()+removeDuplicates(nums)), target);
}