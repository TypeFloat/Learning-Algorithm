#include "link.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr_a = headA, *ptr_b = headB;
    int count_a = 0, count_b = 0;
    while (ptr_a != nullptr) {
        ptr_a = ptr_a->next;
        count_a++;
    }
    while (ptr_b != nullptr) {
        ptr_b = ptr_b->next;
        count_b++;
    }
    ptr_a = headA;
    ptr_b = headB;
    if (count_a > count_b) {
        for (int i = 0; i < count_a - count_b; ++i) {
            ptr_a = ptr_a->next;
        }
    } else {
        for (int i = 0; i < count_b - count_a; ++i) {
            ptr_b = ptr_b->next;
        }
    }
    while (ptr_a != nullptr) {
        if (ptr_a == ptr_b)
            return ptr_a;
        else {
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }
    }
    return nullptr;
}