#include "utils.h"
#include "link.h"

using namespace std;

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
    MyLinkedList() : head(new ListNode()), size(0) {}
    ~MyLinkedList()
    {
        delete head;
    }

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

void solution(ListNode *head, vector<int> &target)
{
    LinkList linkList;
    linkList.head = head;
    linkList.resetSize();
    check(linkList.toVector(), target);
    linkList.head = nullptr;
}

int main(int argc, char **argv)
{
    vector<int> target;
    bool isFeakNode = true;

    // case 1
    target = {};
    MyLinkedList myLinkedList = MyLinkedList();
    solution(myLinkedList.head, target);

    // case 2
    target = {1};
    myLinkedList.addAtHead(1);
    solution(myLinkedList.head, target);

    // case 3
    target = {1, 3};
    myLinkedList.addAtTail(3);
    solution(myLinkedList.head, target);

    // case 4
    target = {1, 2, 3};
    myLinkedList.addAtIndex(1, 2);
    solution(myLinkedList.head, target);

    // case 5
    check(myLinkedList.get(1), 2);

    // case 6
    target = {1, 3};
    myLinkedList.deleteAtIndex(1);
    solution(myLinkedList.head, target);

    // case 7
    solution(myLinkedList.head, target);
}