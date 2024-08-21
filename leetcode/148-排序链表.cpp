#include <gtest/gtest.h>
#include <vector>
#include "link.h"

using namespace std;

class Solution {
   public:
    ListNode *sortList(ListNode *head) {
        int size = 0;
        ListNode *ptr = head;
        while (ptr) {
            ptr = ptr->next;
            ++size;
        }
        if (size <= 1) return head;
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *tail, *head1, *head2, *tail1, *tail2;
        ptr = dummyHead;
        int interval = 1;
        while (interval < size) {
            while (ptr->next) {
                head1 = ptr->next;
                tail1 = ptr;
                for (int i = 0; i < interval; ++i) {
                    if (!tail1->next) break;
                    tail1 = tail1->next;
                }
                head2 = tail1->next;
                tail2 = tail1;
                for (int i = 0; i < interval; ++i) {
                    if (!tail2->next) break;
                    tail2 = tail2->next;
                }
                tail = tail2->next;
                tail1->next = nullptr;
                tail2->next = nullptr;
                pair<ListNode *, ListNode *> info = merge(head1, head2);
                ptr->next = info.first;
                info.second->next = tail;
                ptr = info.second;
            }
            interval *= 2;
            ptr = dummyHead;
        }
        return dummyHead->next;
    }

    pair<ListNode *, ListNode *> merge(ListNode *head1, ListNode *head2) {
        if (!head1 || !head2) {
            ListNode *head = head1 ? head1 : head2;
            ListNode *ptr = head;
            while (ptr->next) ptr = ptr->next;
            return pair<ListNode *, ListNode *>(head, ptr);
        }
        ListNode *head, *ptr1, *ptr2, *ptr;
        if (head1->val < head2->val) {
            head = head1;
            ptr1 = head1->next;
            ptr2 = head2;
        } else {
            head = head2;
            ptr1 = head1;
            ptr2 = head2->next;
        }
        ptr = head;
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = ptr1 ? ptr1 : ptr2;
        while (ptr->next) ptr = ptr->next;
        return pair<ListNode *, ListNode *>(head, ptr);
    }
};

void test(vector<int> &nums) {
    LinkList numsLink = LinkList();
    numsLink.createLink(nums);
    Solution solution = Solution();
    numsLink.head->next = solution.sortList(numsLink.head->next);
    sort(nums.begin(), nums.end());
    ASSERT_EQ(numsLink.toVector(), nums);
}

TEST(Q148, CASE1) {
    vector<int> nums = {4, 2, 1, 3};
    test(nums);
}

TEST(Q148, CASE2) {
    vector<int> nums = {};
    test(nums);
}

TEST(Q148, CASE3) {
    vector<int> nums = {-1, 5, 3, 4, 0};
    test(nums);
}