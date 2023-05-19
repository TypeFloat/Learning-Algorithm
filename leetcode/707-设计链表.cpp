#include "utils.h"


class MyLinkedList
{
private:
    int size;
    ListNode *get_node(int index)
    {
        if (index >= size)
            return nullptr;
        ListNode *ptr = head;
        for (int i = 0; i <= index; ++i)
            ptr = ptr->next;
        return ptr;
    }
public:
    ListNode *head;
    MyLinkedList(): head(new ListNode()), size(0) {}

    int get(int index)
    {   
        ListNode *ptr = get_node(index);
        return ptr == nullptr ? -1 : ptr->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        ListNode *ptr = get_node(index - 1);
        if (ptr == nullptr)
            return;
        ListNode *node = new ListNode(val);
        node->next = ptr->next;
        ptr->next = node;
        ++size;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        ListNode *ptr = get_node(index - 1);
        ListNode *next = ptr->next;
        ptr->next = ptr->next->next;
        --size;
        delete next;
    }
};

vector<int> link2vector(ListNode *head)
{
    vector<int> rtn;
    ListNode *ptr = head->next;
    if (ptr == nullptr)
        return rtn;
    while (ptr != nullptr)
    {
        rtn.emplace_back(ptr->val);
        ptr = ptr->next;
    }
    return rtn;
}

void deleteLink(ListNode *head)
{
    ListNode *ptr = head->next, *tmp;
    while (ptr != nullptr)
    {
        tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    delete head;
}

int main(int argc, char **argv)
{
    vector<int> target;
    bool isFeakNode = true;

    // case 1
    target = {};
    MyLinkedList myLinkedList = MyLinkedList();
    cout << "Case 1: " << check(link2vector(myLinkedList.head), target) << endl;

    // case 2
    target = {1};
    myLinkedList.addAtHead(1);
    cout << "Case 2: " << check(link2vector(myLinkedList.head), target) << endl;

    // case 3
    target = {1, 3};
    myLinkedList.addAtTail(3);
    cout << "Case 3: " << check(link2vector(myLinkedList.head), target) << endl;

    // case 4
    target = {1, 2, 3};
    myLinkedList.addAtIndex(1, 2);
    cout << "Case 4: " << check(link2vector(myLinkedList.head), target) << endl;

    // case 5
    cout << "Case 5: " << check(myLinkedList.get(1), 2) << endl;

    // case 6
    target = {1, 3};
    myLinkedList.deleteAtIndex(1);
    cout << "Case 6: " << check(link2vector(myLinkedList.head), target) << endl;

    // case 7
    cout << "Case 7: " << check(myLinkedList.get(1), 3) << endl;

    deleteLink(myLinkedList.head);
}