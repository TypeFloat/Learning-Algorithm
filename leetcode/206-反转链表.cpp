#include "utils.h"
#include "link.h"

using namespace std;

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *rtn = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rtn;
}

void solution(vector<int> &nums)
{
    LinkList linkList;
    linkList.createLink(nums);
    linkList.head->next = reverseList(linkList.head->next);
    reverse(nums.begin(), nums.end());
    check(linkList.toVector(), nums);
    linkList.deleteLink();
}

int main(int argc, char **argv)
{
    vector<int> nums;

    // case 1
    nums = {1, 2, 3, 4, 5};
    solution(nums);

    // case 2
    nums = {1, 2};
    solution(nums);

    // case 3
    nums = {};
    solution(nums);
}