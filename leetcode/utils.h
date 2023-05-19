#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class T>
bool check(const T& value1, const T& value2)
{
    return value1 == value2;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void createLink(vector<int> &nums, ListNode *head)
{
    ListNode *ptr = head;
    for (int num : nums)
    {
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }
}

void deleteLink(ListNode *head)
{
    ListNode *ptr = head->next, *tmp;
    while (ptr != nullptr)
    {
        tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    head->next = nullptr;
}

vector<int> link2vector(ListNode *head)
{
    vector<int> rtn;
    ListNode *ptr = head->next;
    while (ptr != nullptr)
    {
        rtn.emplace_back(ptr->val);
        ptr = ptr->next;
    }
    return rtn;
}