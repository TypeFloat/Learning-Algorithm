#include "utils.h"


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class LinkList
{
public:
    unsigned int size;
    ListNode *head;
    LinkList() : head(new ListNode()), size(0) {}
    ~LinkList() { delete head; }
    void createLink(std::vector<int> &nums);
    void deleteLink(void);
    ListNode *getNode(int index);
    std::vector<int> toVector(void);
    void resetSize(void);
};