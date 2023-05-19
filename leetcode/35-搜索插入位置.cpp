#include "utils.h"


int searchInsert(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1, mid;
    while (left < right)
    {
        mid = (right - left) / 2 + left;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = right - 1;
        else
            return mid;
    }
    if (nums[left] < target)
        return left + 1;
    else
        return left;
}

int main(int argc, char **argv)
{
    vector<int> nums;
    int target;
    int output;

    // case 1
    nums = vector<int>{1, 3, 5, 6};
    target = 5;
    output = 2;
    cout << "Case 1: " << check(searchInsert(nums, target), output) << endl;

    // case 2
    nums = {1, 3, 5, 6};
    target = 2;
    output = 1;
    cout << "Case 2: " << check(searchInsert(nums, target), output) << endl;

    // case 3
    nums = {1, 3, 5, 6};
    target = 7;
    output = 4;
    cout << "Case 3: " << check(searchInsert(nums, target), output) << endl;
}