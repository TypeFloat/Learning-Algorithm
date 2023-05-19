#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class T>
bool check(const T& value1, const T& value2)
{
    return value1 == value2;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};