#include "utils.h"

using namespace std;

bool repeatedSubstringPattern(string s)
{
    int interval = 1;
    char ch = '\0';
    bool match = true;
    while (interval <= s.size() / 2)
    {
        for (int i = 0; i < interval; ++i)
        {
            if (!match)
                break;
            ch = '\0';
            for (int j = i; j < s.size(); j += interval)
            {
                if (ch == '\0')
                    ch = s[j];
                else
                {
                    if (ch != s[j])
                    {
                        match = false;
                        break;
                    }
                }
            }
        }
        if (match && s.size() % interval == 0)
            return true;
        else
        {
            ++interval;
            match = true;
        }
    }
    return false;
}

void solution(string &s, bool target)
{
    check(repeatedSubstringPattern(s), target);
}

int main(int argc, char **argv)
{
    string s;
    bool target;

    // case 1
    s = "abab";
    target = true;
    solution(s, target);

    // case 2
    s = "aba";
    target = false;
    solution(s, target);

    // case 3
    s = "abcabcabcabc";
    target = true;
    solution(s, target);

    // case 4
    s = "abac";
    target = false;
    solution(s, target);

    // case 5
    s = "aabaaba";
    target = false;
    solution(s, target);
}