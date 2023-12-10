#include <gtest/gtest.h>

#include <vector>

#include "link.h"

using namespace std;

ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *slow = head->next, *fast = head->next->next;
    head->next = nullptr;
    while (fast != nullptr) {
        slow->next = head;
        head = slow;
        slow = fast;
        fast = fast->next;
    }
    slow->next = head;
    return slow;
}

bool judge(vector<int> nums, vector<int> target) {
    LinkList *link_list = new LinkList();
    link_list->createLink(nums);
    link_list->head->next = reverseList(link_list->head->next);
    return target == link_list->toVector();
}

TEST(Q206, CASE1) {
    vector<int> nums = {1, 2, 3, 4, 5}, target = {5, 4, 3, 2, 1};
    ASSERT_TRUE(judge(nums, target));
}

TEST(Q206, CASE2) {
    vector<int> nums = {1, 2}, target = {2, 1};
    ASSERT_TRUE(judge(nums, target));
}

TEST(Q206, CASE3) {
    vector<int> nums = {}, target = {};
    ASSERT_TRUE(judge(nums, target));
}