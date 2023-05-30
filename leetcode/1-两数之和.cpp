#include "utils.h"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, vector<int>> dict;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (dict.find(nums[i]) != dict.end())
            dict[nums[i]].emplace_back(i);
        else
            dict.insert({nums[i], vector<int>{i}});
    }
    for (int num : nums)
    {
        if (dict.find(target - num) != dict.end())
        {
            if (target - num != num)
                return {dict[num][0], dict[target-num][0]};
            else
            {
                if (dict[num].size() >= 2)
                    return {dict[num][0], dict[num][1]};
            }
        }
    }
    return {-1, -1};
}

void solution(vector<int> &nums, vector<int> &output, int target)
{
    vector<int> answer = twoSum(nums, target);
    sort(answer.begin(), answer.end());
    sort(output.begin(), output.end());
    check(answer, output);
}

int main(int argc, char **argv)
{
    vector<int> nums, output;
    int target;

    // case 1
    nums = {2, 7, 11, 15};
    target = 9;
    output = {0, 1};
    solution(nums, output, target);

    // case 2
    nums = {3, 2, 4};
    target = 6;
    output = {1, 2};
    solution(nums, output, target);

    // case 3
    nums = {3, 3};
    target = 6;
    output = {0, 1};
    solution(nums, output, target);
}