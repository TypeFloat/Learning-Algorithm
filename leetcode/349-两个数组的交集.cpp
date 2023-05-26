#include "utils.h"

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums;
    unordered_set<int> numsSet(nums1.begin(), nums1.end());
    for (int num : nums2)
    {
        if (numsSet.find(num) != numsSet.end())
        {
            nums.emplace_back(num);
            numsSet.erase(num);
        }
    }
    return nums;
}

void solution(vector<int> &nums1, vector<int> &nums2, vector<int> &targte)
{
    vector<int> nums = intersection(nums1, nums2);
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
    target = {2};
    solution(nums1, nums2, target);

    // case 2
    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    target = {9, 4};
    solution(nums1, nums2, target);
}