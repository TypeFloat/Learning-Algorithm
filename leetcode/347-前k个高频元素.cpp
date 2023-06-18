#include "utils.h"

using namespace std;

class compare
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> count;
    for (int num : nums)
        count[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> my_queue;
    vector<int> rtn(k);
    for (pair<int, int> c : count)
    {
        if (my_queue.size() < k)
            my_queue.push(c);
        else
        {
            if (c.second > my_queue.top().second)
            {
                my_queue.pop();
                my_queue.push(c);
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        rtn[i] = my_queue.top().first;
        my_queue.pop();
    }
    return rtn;
}

void solution(vector<int> &nums, int k, vector<int> target)
{
    vector<int> rtn = topKFrequent(nums, k);
    sort(rtn.begin(), rtn.end());
    sort(target.begin(), target.end());
    check(rtn, target);
}

int main(int argc, char **argv)
{
    vector<int> nums, target;
    int k;

    // case 1
    nums = {1, 1, 1, 2, 2, 3};
    k = 2;
    target = {1, 2};
    solution(nums, k, target);

    // case 2
    nums = {1};
    k = 1;
    target = {1};
    solution(nums, k, target);
}