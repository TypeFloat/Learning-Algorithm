#include "utils.h"

using namespace std;

int binarySearch(vector<int> &nums, int target, int left, int right);

vector<int> searchRange(vector<int> &nums, int target)
{
    int left = nums.size(), right = -1, low = 0, high = nums.size() - 1;
    // 使用的思路是不断在一个缩小的区间里寻找目标，每一次查找都是一次二分查找。
    do
    {
        low = binarySearch(nums, target, 0, left - 1);
        if (low != -1)
            left = low;
    } while (low != -1);
    do
    {
        high = binarySearch(nums, target, right + 1, nums.size() - 1);
        if (high != -1)
            right = high;
    } while (high != -1);
    // 如果 right = -1 说明 nums 里没有 target，则返回 {-1, -1}
    if (right < 0)
        return {-1, -1};
    else
        return {left, right};
}

int binarySearch(vector<int> &nums, int target, int left, int right)
{
    int mid;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

void solution(vector<int> &nums, vector<int> &output, int target)
{
    check(searchRange(nums, target), output);
}

int main(int argc, char **argv)
{
    vector<int> nums, output;
    int target;

    // case 1
    nums = {5, 7, 7, 8, 8, 10};
    output = {3, 4};
    target = 8;
    solution(nums, output, target);

    // case 2
    nums = {5, 7, 7, 8, 8, 10};
    output = {-1, -1};
    target = 6;
    solution(nums, output, target);

    // case 3
    nums = {};
    output = {-1, -1};
    target = 0;
    solution(nums, output, target);
}