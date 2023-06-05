#include "utils.h"

using namespace std;

string reverseStr(string s, int k)
{
    bool flag = true;
    int start = 0, end = 0;
    while (start < s.size())
    {
        end = min(start + k, static_cast<int>(s.size()));
        if (flag)
            reverse(s.begin()+start, s.begin()+end);
        flag = !flag;
        start = end;
    }
    return s;
}

void solution(string &s, int k, string &t)
{
    check(reverseStr(s, k), t);
}

int main(int argc, char **argv)
{
    string s, t;
    int k;

    // case 1
    s = "abcdefg";
    t = "bacdfeg";
    k = 2;
    solution(s, k, t);

    // case 2
    s = "abcd";
    t = "bacd";
    k = 2;
    solution(s, k, t);
}