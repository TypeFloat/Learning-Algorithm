#include "utils.h"
#include "link.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    int lenA = 0, lenB = 0, lenGap;
    ListNode *ptrA = headA, *ptrB = headB;
    // 记录A的长度
    while (ptrA != nullptr)
    {
        ++lenA;
        ptrA = ptrA->next;
    }
    // 记录B的长度
    while (ptrB != nullptr)
    {
        ++lenB;
        ptrB = ptrB->next;
    }
    ptrA = headA;
    ptrB = headB;
    if (lenA < lenB)
    {
        lenGap = lenB - lenA;
        while (lenGap--)
            ptrB = ptrB->next;
    }
    else if (lenA > lenB)
    {
        lenGap = lenA - lenB;
        while (lenGap--)
            ptrA = ptrA->next;
    }
    while (ptrA != nullptr)
    {
        if (ptrA == ptrB)
            return ptrA;
        else
        {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
    return nullptr;
}

void catLink(ListNode *front, ListNode *back)
{
    ListNode *ptr = front;
    while (ptr->next != nullptr)
        ptr = ptr->next;
    ptr->next = back;
}

void solution(vector<int> &numsA, vector<int> &numsB, vector<int> &numsIntersection)
{
    LinkList listA, listB, listC, listD;
    listA.createLink(numsA);
    listB.createLink(numsB);
    listC.createLink(numsIntersection);
    ListNode *tailA = listA.getNode(-1);
    ListNode *tailB = listB.getNode(-1);
    tailA->next = listC.head->next;
    tailB->next = listC.head->next;
    listD.head->next = getIntersectionNode(listA.head->next, listB.head->next);
    listD.resetSize();
    check(listD.toVector(), listC.toVector());
    listD.deleteLink();
    listC.deleteLink();
    listB.deleteLink();
    listA.deleteLink();
}

int main(int argc, char **argv)
{
    ListNode *headA = new ListNode(),
             *headB = new ListNode(),
             *intersectionNode = new ListNode(),
             *tmpNode = new ListNode();
    vector<int> numsA, numsB, numsIntersection;

    // case 1
    numsA = {4, 1};
    numsB = {5, 6, 1};
    numsIntersection = {8, 4, 5};
    solution(numsA, numsB, numsIntersection);

    // case 2
    numsA = {1, 9, 1};
    numsB = {3};
    numsIntersection = {2, 4};
    solution(numsA, numsB, numsIntersection);

    // case 3
    numsA = {2, 6, 4};
    numsB = {1, 5};
    numsIntersection = {};
    solution(numsA, numsB, numsIntersection);
}