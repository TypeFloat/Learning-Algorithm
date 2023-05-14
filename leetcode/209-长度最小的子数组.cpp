#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int left = 0, right = 0, sum = nums[0], minLength = nums.size() + 1;
    while (left <= right)
    {
        if (sum >= target)
        {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
        else
        {
            if (right == nums.size() - 1)
                break;
            sum += nums[++right];
        }
    }
    return minLength == nums.size() + 1 ? 0 : minLength;
}

int main(int argc, char **argv)
{
    vector<int> nums;
    int target, output;

    // case 1
    nums = vector<int>{2, 3, 1, 2, 4, 3};
    target = 7;
    output = 2;
    cout << "Case 1: " << check(output, minSubArrayLen(target, nums)) << endl;

    // case 2
    nums = vector<int>{1, 4, 4};
    target = 4;
    output = 1;
    cout << "Case 2: " << check(output, minSubArrayLen(target, nums)) << endl;

    // case 3
    nums = vector<int>{1, 1, 1, 1, 1, 1, 1};
    target =11;
    output = 0;
    cout << "Case 3: " << check(output, minSubArrayLen(target, nums)) << endl;
}