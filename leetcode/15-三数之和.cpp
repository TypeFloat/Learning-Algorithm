#include "utils.h"

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> rtn;
    for (int i = 0; i < nums.size(); ++i)
    {
        int j = i + 1, k = nums.size() - 1;
        if (i > 0 && nums[i-1] == nums[i])
            continue;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                rtn.push_back({nums[i], nums[j++], nums[k--]});
                while (j < k && nums[j] == nums[j-1])
                    ++j;
                while (j < k && nums[k] == nums[k+1])
                    --k;
            }
            else if (sum > 0)
                --k;
            else
                ++j;
        }
    }
    return rtn;
}

void solution(vector<int> nums, vector<vector<int>> target)
{
    for (vector<int> &num : target)
        sort(num.begin(), num.end());
    vector<vector<int>> output = threeSum(nums);
    for (vector<int> &num : output)
        sort(num.begin(), num.end());
    check(output, target);
}

int main(int argc, char **argv)
{
    vector<int> nums;
    vector<vector<int>> target;

    // case 1
    nums = {-1, 0, 1, 2, -1, 4};
    target = {{-1, -1, 2}, {-1, 0, 1}};
    solution(nums, target);

    // case 2
    nums = {0, 1, 1};
    target = {};
    solution(nums, target);

    // case 3
    nums = {0, 0, 0};
    target = {{0, 0, 0}};
    solution(nums, target);

    // case 4
    nums = {0, 0, 0, 0};
    target = {{0, 0, 0}};
    solution(nums, target);

    // case 5
    nums = {-2, 0, 1, 1, 2};
    target = {{-2, 0, 2}, {-2, 1, 1}};
    solution(nums, target);
}