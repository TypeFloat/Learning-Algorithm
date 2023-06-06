#include "utils.h"

using namespace std;

string replaceSpace(string s)
{
    int count = 0;
    for (char ch : s)
    {
        if (ch == ' ')
            ++count;
    }
    int fast  = s.size() - 1;
    s.resize(s.size() + 2 * count);
    int slow = s.size() - 1;
    while (fast >= 0)
    {
        if (s[fast] == ' ')
        {
            s[slow--] = '0';
            s[slow--] = '2';
            s[slow--] = '%';
        }
        else
            s[slow--] = s[fast];
        --fast;
    }
    return s;
}

void solution(string &s, string &t)
{
    check(replaceSpace(s), t);
};

int main(int argc, char **argv)
{
    string s, t;

    // case 1
    s = "We are happy.";
    t = "We%20are%20happy.";
    solution(s, t);
}