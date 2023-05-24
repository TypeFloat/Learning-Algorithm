#include "utils.h"

using namespace std;


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

void solution(vector<int> &nums, int output, int target)
{
    check(searchInsert(nums, target), output);
}

int main(int argc, char **argv)
{
    vector<int> nums;
    int target, output;

    // case 1
    nums = {1, 3, 5, 6};
    target = 5;
    output = 2;
    solution(nums, output, target);
    
    // case 2
    nums = {1, 3, 5, 6};
    target = 2;
    output = 1;
    solution(nums, output, target);

    // case 3
    nums = {1, 3, 5, 6};
    target = 7;
    output = 4;
    solution(nums, output, target);
}