#include "utils.h"


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
    head->next = removeElements(head->next, val);
    check(link2vector(head), target);
    deleteLink(head);

    // case 2
    nums = {};
    val = 1;
    target = {};
    createLink(nums, head);
    head->next = removeElements(head->next, val);
    check(link2vector(head), target);
    deleteLink(head);

    // case 3
    nums = {7, 7, 7, 7};
    val = 7;
    target = {};
    createLink(nums, head);
    head->next = removeElements(head->next, val);
    check(link2vector(head), target);
    deleteLink(head);

    delete head;
}