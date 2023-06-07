#include "utils.h"

using namespace std;

string reverseWords(string s)
{
    int slow = 0, fast = 0;
    while (slow < s.size())
    {
        if (s[slow] != ' ')
        {
            while (s[++fast] != ' ' && fast < s.size());
            reverse(s.begin()+slow, s.begin()+fast);
            slow = fast;
        }
        else
            ++slow;
    }
    reverse(s.begin(), s.end());
    slow = 0;
    fast = -1;
    bool flag = false;
    while (++fast < s.size())
    {
        if (s[fast] != ' ')
        {
            s[slow++] = s[fast];
            flag = true;
        }
        else
        {
            if (flag)
            {
                s[slow++] = s[fast];
                flag = false;
            }
        }
    }
    if (s[slow-1] == ' ')
        --slow;
    return s.substr(0, slow);
}

void solution(string &s, string &t)
{
    check(reverseWords(s), t);
}

int main(int argc, char **argv)
{
    string s, t;

    // case 1
    s = "the sky is blue";
    t = "blue is sky the";
    solution(s, t);

    // case 2
    s = "   hello world  ";
    t = "world hello";
    solution(s, t);

    // case 3
    s = "a good   example";
    t = "example good a";
    solution(s, t);
}