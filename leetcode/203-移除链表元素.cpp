#include "utils.h"
#include "link.h"

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

void solution(vector<int> &nums, vector<int> &target, int val)
{
    LinkList linkList;
    linkList.createLink(nums);
    linkList.head->next = removeElements(linkList.head->next, val);
    linkList.resetSize();
    check(linkList.toVector(), target);
    linkList.deleteLink();
}

int main(int argc, char **argv)
{
    vector<int> nums, target;
    int val;

    // case 1
    nums = {1, 2, 6, 3, 4, 5, 6};
    val = 6;
    target = {1, 2, 3, 4, 5};
    solution(nums, target, val);

    // case 2
    nums = {};
    val = 1;
    target = {};
    solution(nums, target, val);

    // case 3
    nums = {7, 7, 7, 7};
    val = 7;
    target = {};
    solution(nums, target, val);
}