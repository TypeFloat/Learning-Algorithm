#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int backspace(string &s, int index)
{
    if (s[index] == '#')
    {
        // 退格时要退两格
        int time = 2;
        while (time--)
        {
            --index;
            if (index < 0)
                return -1;
            if (s[index] == '#')
                time += 2;
        }
    }
    return index;
}

bool backspaceCompare(string s, string t)
{
    int ptrS = s.size() - 1, ptrT = t.size() - 1;
    while (ptrS>=0 && ptrT>=0)
    {
        ptrS = backspace(s, ptrS);
        ptrT = backspace(t, ptrT);
        if (ptrS >= 0 && ptrT >= 0 && s[ptrS--] != t[ptrT--])
            return false;
    }
    // 退出循环后，要再次执行退格操作
    if (ptrS >= 0)
        ptrS = backspace(s, ptrS);
    if (ptrT >= 0)
        ptrT = backspace(t, ptrT);
    return ptrS == ptrT;
}

int main(int argc, char **argv)
{
    string s, t;
    bool target;

    // case 1
    s = "ab#c";
    t = "ad#c";
    target = true;
    cout << "Case 1: " << check(target, backspaceCompare(s, t)) << endl;
    
    // case 2
    s = "ab##";
    t = "c#d#";
    target = true;
    cout << "Case 2: " << check(target, backspaceCompare(s, t)) << endl;

    // case 3
    s = "a#c";
    t = "b";
    target = false;
    cout << "Case 3: " << check(target, backspaceCompare(s, t)) << endl;
}