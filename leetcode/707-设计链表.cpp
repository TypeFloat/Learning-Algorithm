#include <gtest/gtest.h>

#include "link.h"

using namespace std;

class MyLinkedList {
   public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode();
    }
    int get(int index) {
        if (index + 1 > size) return -1;
        ListNode *ptr = this->head;
        for (int i = 0; i <= index; ++i) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
    void addAtHead(int val) { addAtIndex(0, val); }
    void addAtTail(int val) { addAtIndex(this->size, val); }
    void addAtIndex(int index, int val) {
        if (index > this->size) return;
        ListNode *ptr = this->head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        ListNode *node = new ListNode(val);
        node->next = ptr->next;
        ptr->next = node;
        this->size += 1;
    }
    void deleteAtIndex(int index) {
        if (index + 1 > size) return;
        ListNode *ptr = this->head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        ListNode *node = ptr->next;
        ptr->next = ptr->next->next;
        delete node;
        this->size -= 1;
    }

   private:
    int size;
    ListNode *head;
};

TEST(Q707, CASE1) {
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    ASSERT_EQ(myLinkedList.get(1), 2);
    myLinkedList.deleteAtIndex(1);
    ASSERT_EQ(myLinkedList.get(1), 3);
}