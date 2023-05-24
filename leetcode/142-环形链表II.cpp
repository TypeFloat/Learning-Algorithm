#include "utils.h"
#include "link.h"

using namespace std;

ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *fast = head, *slow = head;
    while (true)
    {
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

void solution(vector<int> nums, int pos)
{
    LinkList linkList;
    linkList.createLink(nums);
    if (pos >= 0)
    {
        ListNode *tail = linkList.getNode(-1);
        ListNode *cycle = linkList.getNode(pos);
        tail->next = cycle;
        check(detectCycle(linkList.head), cycle);
        tail->next = nullptr;
    }
    else
        check(detectCycle(linkList.head), (ListNode *)nullptr);
    linkList.deleteLink();
}

int main(int argc, char **argv)
{
    vector<int> nums;
    int pos;

    // case 1
    nums = {3, 2, 0, -4};
    pos = 1;
    solution(nums, pos);

    // case 2
    nums = {1, 2};
    pos = 0;
    solution(nums, pos);

    // case 3
    nums = {1};
    pos = -1;
    solution(nums, pos);
}