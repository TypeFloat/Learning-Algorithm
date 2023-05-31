#include "utils.h"

using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> countA, countB;
    for (int i = 0; i < nums1.size(); ++i)
    {
        for (int j = 0; j < nums3.size(); ++j)
        {
            ++countA[nums1[i] + nums2[j]];
            ++countB[nums3[i] + nums4[j]];
        }
    }
    int count = 0;
    for (auto pairA : countA)
    {
        auto pairB = countB.find(-pairA.first);
        if (pairB != countB.end())
            count += pairA.second * pairB->second;
    }
    return count;
}

void solution(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4, int target)
{
    check(fourSumCount(nums1, nums2, nums3, nums4), target);
}

int main(int argc, char **argv)
{
    vector<int> nums1, nums2, nums3, nums4;
    int target;

    // case 1
    nums1 = {1, 2};
    nums2 = {-2, -1};
    nums3 = {-1, 2};
    nums4 = {0, 2};
    target = 2;
    solution(nums1, nums2, nums3, nums4, target);

    // case 2
    nums1 = {0};
    nums2 = {0};
    nums3 = {0};
    nums4 = {0};
    target = 1;
    solution(nums1, nums2, nums3, nums4, target);
}