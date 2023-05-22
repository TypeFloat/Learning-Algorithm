#include "utils.h"


ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *rtn = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rtn;
}

int main(int argc, char **argv)
{
    ListNode *head = new ListNode();
    vector<int> nums;

    // case 1
    nums = {1, 2, 3, 4, 5};
    createLink(nums, head);
    head->next = reverseList(head->next);
    reverse(nums.begin(), nums.end());
    check(link2vector(head), nums);
    deleteLink(head);

    // case 2
    nums = {1, 2};
    createLink(nums, head);
    head->next = reverseList(head->next);
    reverse(nums.begin(), nums.end());
    check(link2vector(head), nums);
    deleteLink(head);

    // case 3
    nums = {};
    createLink(nums, head);
    head->next = reverseList(head->next);
    reverse(nums.begin(), nums.end());
    check(link2vector(head), nums);
    deleteLink(head);

    delete head;
}