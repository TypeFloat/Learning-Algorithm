#include "utils.h"

using namespace std;

bool isValid(string s)
{
    stack<char> my_stack;
    for (char ch : s)
    {
        if (my_stack.empty())
            my_stack.push(ch);
        else
        {
            if ((ch == '}' && my_stack.top() == '{') ||
                (ch == ']' && my_stack.top() == '[') ||
                (ch == ')' && my_stack.top() == '('))
                my_stack.pop();
            else
                my_stack.push(ch);
        }
    }
    return my_stack.empty();
}

void solution(string &s, bool target)
{
    check(isValid(s), target);
}

int main(int argc, char **argv)
{
    string s;
    bool target;

    // case 1
    s = "()";
    target = true;
    solution(s, target);

    // case 2
    s = "()[]{}";
    target = true;
    solution(s, target);

    // case 3
    s = "(]";
    target = false;
    solution(s, target);
}