#include "utils.h"

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

int main(int argc, char **argv)
{
    vector<int> nums, target;
    ListNode *head = new ListNode();

    // case 1
    nums = {1, 2, 3, 4};
    target = {2, 1, 4, 3};
    createLink(nums, head);
    head->next = swapPairs(head->next);
    check(link2vector(head), target);
    deleteLink(head);

    // case 2
    nums = {};
    target = {};
    createLink(nums, head);
    head->next = swapPairs(head->next);
    check(link2vector(head), target);
    deleteLink(head);

    // case 3
    nums = {1};
    target = {1};
    createLink(nums, head);
    head->next = swapPairs(head->next);
    check(link2vector(head), target);
    deleteLink(head);
    
    delete head;
}