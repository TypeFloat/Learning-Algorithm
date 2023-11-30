#include <gtest/gtest.h>

#include <vector>

#include "link.h"

using namespace std;

ListNode *removeElements(ListNode *head, int val) {
    ListNode *ptr = new ListNode(), *tmp;
    ptr->next = head;
    head = ptr;
    while (ptr->next != nullptr) {
        if (ptr->next->val == val) {
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            delete tmp;
        } else {
            ptr = ptr->next;
        }
    }
    ptr = head->next;
    delete head;
    return ptr;
}

bool judge(vector<int> &nums, vector<int> &target, int val) {
    LinkList link_list;
    link_list.createLink(nums);
    link_list.head->next = removeElements(link_list.head->next, val);
    return target == link_list.toVector();
}

TEST(Q203, CASE1) {
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6}, target = {1, 2, 3, 4, 5};
    ASSERT_TRUE(judge(nums, target, 6));
}

TEST(Q203, CASE2) {
    vector<int> nums = {}, target = {};
    ASSERT_TRUE(judge(nums, target, 1));
}

TEST(Q203, CASE3) {
    // case 3
    vector<int> nums = {7, 7, 7, 7}, target = {};
    ASSERT_TRUE(judge(nums, target, 7));
}