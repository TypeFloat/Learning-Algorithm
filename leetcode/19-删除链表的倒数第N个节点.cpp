#include "utils.h"
#include "link.h"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slowPtr = head, *fastPtr = head;
    while (n--)
        fastPtr = fastPtr->next;
    // 该种情况意味着要删除的节点是头节点，因此直接返回头节点的next
    if (fastPtr == nullptr)
        return head->next;
    while (fastPtr->next != nullptr)
    {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }
    slowPtr->next = slowPtr->next->next;
    return head;
}

void solution(vector<int> &nums, vector<int> &target, int n)
{
    LinkList linkList;
    linkList.createLink(nums);
    linkList.head->next = removeNthFromEnd(linkList.head->next, n);
    linkList.resetSize();
    check(linkList.toVector(), target);
    linkList.deleteLink();
}

int main(int argc, char **argv)
{
    vector<int> nums, target;
    int n;

    // case 1
    nums = {1, 2, 3, 4, 5};
    target = {1, 2, 3, 5};
    n = 2;
    solution(nums, target, n);
    
    // case 2
    nums = {1};
    target = {};
    n = 1;
    solution(nums, target, n);

    // case 3
    nums = {1, 2};
    target = {1};
    n = 1;
    solution(nums, target, n);
}