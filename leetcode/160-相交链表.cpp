#include "utils.h"

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
    createLink(numsA, headA);
    createLink(numsB, headB);
    createLink(numsIntersection, intersectionNode);
    catLink(headA, intersectionNode->next);
    catLink(headB, intersectionNode->next);
    tmpNode->next = getIntersectionNode(headA, headB);
    check(link2vector(tmpNode), link2vector(intersectionNode));
    deleteLink(intersectionNode);
    deleteLink(headB);
    deleteLink(headA);

    // case 2
    numsA = {1, 9, 1};
    numsB = {3};
    numsIntersection = {2, 4};
    createLink(numsA, headA);
    createLink(numsB, headB);
    createLink(numsIntersection, intersectionNode);
    catLink(headA, intersectionNode->next);
    catLink(headB, intersectionNode->next);
    tmpNode->next = getIntersectionNode(headA, headB);
    check(link2vector(tmpNode), link2vector(intersectionNode));
    deleteLink(intersectionNode);
    deleteLink(headB);
    deleteLink(headA);

    // case 3
    numsA = {2, 6, 4};
    numsB = {1, 5};
    numsIntersection = {};
    createLink(numsA, headA);
    createLink(numsB, headB);
    createLink(numsIntersection, intersectionNode);
    catLink(headA, intersectionNode->next);
    catLink(headB, intersectionNode->next);
    tmpNode->next = getIntersectionNode(headA, headB);
    check(link2vector(tmpNode), link2vector(intersectionNode));
    deleteLink(intersectionNode);
    deleteLink(headB);
    deleteLink(headA);
}