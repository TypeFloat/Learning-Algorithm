#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *feakHead = new ListNode(0, head), *ptr = feakHead;
    while (ptr != nullptr && ptr->next != nullptr)
    {
        if (ptr->next->val == val)
        {
            ptr->next = ptr->next->next;
        }
        else
            ptr = ptr->next;
    }
    return feakHead->next;
}

void createLink(vector<int> &nums, ListNode *head)
{
    ListNode *ptr = head;
    for (int num : nums)
    {
        ptr->val = num;
        ptr->next = new ListNode();
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

}

vector<int> link2vector(ListNode *head)
{
    vector<int> rtn;
    ListNode *ptr = head;
    while (ptr->next != nullptr)
    {
        rtn.emplace_back(ptr->val);
        ptr = ptr->next;
    }
    return rtn;
}

int main(int argc, char **argv)
{
    ListNode *head = new ListNode();
    vector<int> nums, target;
    int val;

    // case 1
    nums = {1, 2, 6, 3, 4, 5, 6};
    val = 6;
    target = {1, 2, 3, 4, 5};
    createLink(nums, head);
    head = removeElements(head, val);
    cout << "Case 1: " << check(link2vector(head), target) << endl;
    deleteLink(head);

    // case 2
    nums = {};
    val = 1;
    target = {};
    createLink(nums, head);
    head = removeElements(head, val);
    cout << "Case 2: " << check(link2vector(head), target) << endl;
    deleteLink(head);

    // case 3
    nums = {7, 7, 7, 7};
    val = 7;
    target = {};
    createLink(nums, head);
    head = removeElements(head, val);
    cout << "Case 3: " << check(link2vector(head), target) << endl;
    deleteLink(head);

    delete head;
}