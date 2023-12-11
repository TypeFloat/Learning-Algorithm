#include <gtest/gtest.h>

#include <vector>

#include "link.h"

using namespace std;

ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) return nullptr;
    ListNode *dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode *ptr1 = dummy_head, *ptr2 = head, *ptr3 = head->next;
    while (ptr2 && ptr3) {
        ptr1->next = ptr3;
        ptr2->next = ptr3->next; 
        ptr3->next = ptr2;
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        if (ptr2 == nullptr) break;
        ptr3 = ptr1->next->next;
    }
    return dummy_head->next;
}

void judge(vector<int> &nums, vector<int> &target) {
    LinkList *link_list = new LinkList();
    link_list->createLink(nums);
    link_list->head->next = swapPairs(link_list->head->next);
    ASSERT_TRUE(link_list->toVector() == target);
}

TEST(Q24, CASE1) {
    vector<int> nums = {1, 2, 3, 4}, target = {2, 1, 4, 3};
    judge(nums, target);
}

TEST(Q24, CASE2) {
    vector<int> nums = {}, target = {};
    judge(nums, target);
}

TEST(Q24, CASE3) {
    vector<int> nums = {1}, target = {1};
    judge(nums, target);
}