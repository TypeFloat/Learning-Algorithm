#include "utils.h"

using namespace std;

string removeDuplicates(string s)
{
    string my_stack;
    for (char ch : s)
    {
        if (!my_stack.empty() && my_stack.back() == ch)
            my_stack.pop_back();
        else
            my_stack.push_back(ch);
    }
    return my_stack;
}

void solution(string &s, string &t)
{
    check(removeDuplicates(s), t);
}

int main(int argc, char **argv)
{
    string s, t;

    // case 1
    s = "abbaca";
    t = "ca";
    solution(s, t);

    // case 2
    s = "azxxzy";
    t = "ay";
    solution(s, t);
}