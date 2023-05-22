#include "utils.h"


vector<int> sortedSquares(vector<int>& nums)
{
    if (nums.size() == 1)
        return {nums[0] * nums[0]};
    vector<int> rtn(nums.size());
    // 解体策略是从两头向中间走，而不是从中间向两头走，因为不好确定中间元素的位置
    int left = 0, right = nums.size() - 1, index = rtn.size() - 1, leftSquare, rightSquare;
    while (index >= 0)
    {
        leftSquare = nums[left] * nums[left];
        rightSquare = nums[right] * nums[right];
        if (leftSquare < rightSquare)
        {
            rtn[index--] = rightSquare;
            --right;
        }
        else
        {
            rtn[index--] = leftSquare;
            ++left;
        }
    }
    return rtn;
}

int main(int argc, char **argv)
{
    vector<int> nums, target;

    // case 1
    nums = vector<int>{-4, -1, 0, 3, 10};
    target = vector<int>{0, 1, 9, 16, 100};
    check(sortedSquares(nums), target);

    // case 2
    nums = vector<int>{-7, -3, 2, 3, 11};
    target = vector<int>{4, 9, 9, 49, 121};
    check(sortedSquares(nums), target);
}