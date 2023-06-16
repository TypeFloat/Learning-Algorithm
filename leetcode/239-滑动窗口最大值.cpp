#include "utils.h"

using namespace std;

class SingleDeque
{
    // 特殊的单调队列
private:
    deque<int> my_deque;
public:
    void push(int elem)
    {
        while (!my_deque.empty() && elem > my_deque.back())
            my_deque.pop_back();
        my_deque.push_back(elem);
    }

    void pop(int elem)
    {
        if (!my_deque.empty() && my_deque.front() == elem)
            my_deque.pop_front();
    }

    int front()
    {
        return my_deque.front();
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    SingleDeque my_deque;
    vector<int> result(nums.size()-k+1, 0);
    for (int i = 0; i < k; ++i)
        my_deque.push(nums[i]);
    for (int i = 0; i < nums.size()-k+1; ++i)
    {
        result[i] = my_deque.front();
        my_deque.pop(nums[i]);
        if (i + k < nums.size())
            my_deque.push(nums[i+k]);
    }
    return result;
}

void solution(vector<int> &nums, int k, vector<int> &target)
{
    check(maxSlidingWindow(nums, k), target);
}

int main(int argc, char **argv)
{
    vector<int> nums, target;
    int k;

    // case 1
    nums = {1, 3, -1, -3, 5, 3, 6, 7};
    target = {3, 3, 5, 5, 6, 7};
    k = 3;
    solution(nums, k, target);

    // case 2
    nums = {1};
    target = {1};
    k = 1;
    solution(nums, k, target);
}