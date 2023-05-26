#include "utils.h"

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums;
    // 用 unordered_map 也可以，因为题目限制了 0 <= num <= 1000，因此可以创建一个数组
    vector<int> dict(1001, 0);
    for (int num : nums1)
        dict[num]++;
    for (int num : nums2)
    {
        if (dict[num] > 0)
        {
            dict[num]--;
            nums.emplace_back(num);
        }
    }
    return nums;
}

void solution(vector<int> &nums1, vector<int> &nums2, vector<int> &targte)
{
    vector<int> nums = intersect(nums1, nums2);
    sort(nums.begin(), nums.end());
    sort(targte.begin(), targte.end());
    check(nums, targte);
}

int main(int argc, char **argv)
{
    vector<int> nums1, nums2, target;

    // case 1
    nums1 = {1, 2, 2, 1};
    nums2 = {2, 2};
    target = {2, 2};
    solution(nums1, nums2, target);

    // case 2
    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    target = {9, 4};
    solution(nums1, nums2, target);
}