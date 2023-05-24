#include "utils.h"

using namespace std;

int removeDuplicates(vector<int> &nums)
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

void solution(vector<int> &nums, vector<int> &target)
{
    check(vector<int>(nums.begin(), nums.begin()+removeDuplicates(nums)), target);
}

int main(int argc, char **argv)
{
    vector<int> nums, target;

    // case1
    nums = {1, 1, 2};
    target = {1, 2};
    solution(nums, target);

    // case2
    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    target = {0, 1, 2, 3, 4};
    solution(nums, target);
}