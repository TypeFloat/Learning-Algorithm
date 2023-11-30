#include "link.h"

void LinkList::createLink(std::vector<int> &nums) {
    ListNode *ptr = this->head;
    for (int num : nums) {
        this->size++;
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }
}

void LinkList::deleteLink(void) {
    ListNode *ptr = this->head->next, *tmp;
    while (ptr != nullptr) {
        tmp = ptr;
        ptr = ptr->next;
        tmp = nullptr;
        this->size--;
        delete tmp;
    }
}

ListNode *LinkList::getNode(int index) {
    if (index < 0) index = this->size + index;
    if (index < 0 || index >= this->size) return nullptr;
    ListNode *ptr = this->head->next;
    for (int i = 0; i < index; ++i) ptr = ptr->next;
    return ptr;
}

std::vector<int> LinkList::toVector(void) {
    this->resetSize();
    std::vector<int> nums(this->size);
    ListNode *ptr = head->next;
    for (int i = 0; i < this->size; ++i) {
        nums[i] = ptr->val;
        ptr = ptr->next;
    }
    return nums;
}

void LinkList::resetSize(void) {
    int size = 0;
    ListNode *ptr = this->head->next;
    while (ptr != nullptr) {
        size++;
        ptr = ptr->next;
    }
    this->size = size;
}