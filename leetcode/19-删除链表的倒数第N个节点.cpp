#include <gtest/gtest.h>

#include <vector>

#include "link.h"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode *ptr = dummy_head;
    for (int i = 0; i < n - 1; ++i) {
        head = head->next;
    }
    while (head->next != nullptr) {
        head = head->next;
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    return dummy_head->next;
}

void judge(vector<int> &nums, vector<int> &target, int n) {
    LinkList *link_list = new LinkList();
    link_list->createLink(nums);
    link_list->head->next = removeNthFromEnd(link_list->head->next, n);
    ASSERT_TRUE(target == link_list->toVector());
}

TEST(Q19, CASE1) {
    vector<int> nums = {1, 2, 3, 4, 5}, target = {1, 2, 3, 5};
    judge(nums, target, 2);
}

TEST(Q19, CASE2) {
    vector<int> nums = {1}, target = {};
    judge(nums, target, 1);
}
TEST(Q19, CASE3) {
    vector<int> nums = {1, 2}, target = {1};
    judge(nums, target, 1);
}