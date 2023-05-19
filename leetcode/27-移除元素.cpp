#include "utils.h"


int removeElement(vector<int>& nums, int val)
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

int main(int argc, char **argv)
{
    vector<int> nums, target;
    int val;

    // case1
    nums = vector<int>{3, 2, 2, 3};
    val = 3;
    target = vector<int>{2, 2};
    cout << "Case 1: " << check(vector<int>(nums.begin(), nums.begin()+removeElement(nums, val)), target) << endl;

    // case2
    nums = vector<int>{0, 1, 2, 2, 3, 0, 4, 2};
    val = 2;
    target = vector<int>{0, 1, 3, 0, 4};
    cout << "Case 2: " << check(vector<int>(nums.begin(), nums.begin()+removeElement(nums, val)), target) << endl;
}