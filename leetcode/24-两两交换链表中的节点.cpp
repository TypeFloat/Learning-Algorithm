#include "utils.h"
#include "link.h"

using namespace std;

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *preNode = head, *nextNode = head->next;
    preNode->next = nextNode->next;
    nextNode->next = preNode;
    preNode->next = swapPairs(preNode->next);
    return nextNode;
}

void solution(vector<int> nums, vector<int> target)
{
    LinkList linkList;
    linkList.createLink(nums);
    linkList.head->next = swapPairs(linkList.head->next);
    check(linkList.toVector(), target);
    linkList.deleteLink();
}

int main(int argc, char **argv)
{
    vector<int> nums, target;

    // case 1
    nums = {1, 2, 3, 4};
    target = {2, 1, 4, 3};
    solution(nums, target);

    // case 2
    nums = {};
    target = {};
    solution(nums, target);

    // case 3
    nums = {1};
    target = {1};
    solution(nums, target);
}