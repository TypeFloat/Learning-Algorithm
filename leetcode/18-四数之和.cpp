#include "utils.h"

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> rtn;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (j > i + 1 && nums[j] == nums[j-1])
                continue;
            int l = j + 1, r = nums.size() - 1;
            while (l < r)
            {
                // 根据题目的数据上限，需要使用长整形
                long int sum = (long int)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target)
                {
                    rtn.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l-1])
                        ++l;
                    while (l < r && nums[r] == nums[r+1])
                        --r;
                }
                else if (sum < target)
                    ++l;
                else
                    --r;
            }
        }
    }
    return rtn;
}

void solution(vector<int> nums, int target, vector<vector<int>> output)
{
    vector<vector<int>> rtn = fourSum(nums, target);
    for (vector<int> &num : rtn)
        sort(rtn.begin(), rtn.end());
    for (vector<int> &num : output)
        sort(rtn.begin(), rtn.end());
    check(rtn, output);
}

int main(int argc, char **argv)
{
    vector<int> nums;
    vector<vector<int>> output;
    int target;

    // case 1
    nums = {1, 0, -1, 0, -2, 2};
    target = 0;
    output = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    solution(nums, target, output);

    // case 2
    nums = {2, 2, 2, 2, 2};
    target = 8;
    output = {{2, 2, 2, 2}};
    solution(nums, target, output);
}