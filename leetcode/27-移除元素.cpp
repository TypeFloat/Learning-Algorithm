#include "utils.h"

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int fast = 0, slow = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

void solution(vector<int> &nums, vector<int> &target, int val)
{
    check(vector<int>(nums.begin(), nums.begin() + removeElement(nums, val)), target);
}

int main(int argc, char **argv)
{
    vector<int> nums, target;
    int val;

    // case1
    nums = {3, 2, 2, 3};
    target = {2, 2};
    val = 3;
    solution(nums, target, val);

    // case2
    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    target = {0, 1, 3, 0, 4};
    val = 2;
    solution(nums, target, val);
}