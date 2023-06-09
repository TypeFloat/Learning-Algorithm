#include "utils.h"

using namespace std;

vector<int> getNext(string &needle)
{
    vector<int> next(needle.size(), 0);
    int j = 0;
    // next[i]分两种情况进行赋值
    for (int i = 1; i < needle.size(); ++i)
    {
        // 如果相同，前缀尾向前，next[i] = next[i - 1] + 1
        if (needle[i] == needle[j])
        {
            next[i] = next[i - 1] + 1;
            ++j;
        }
        // 如果不相同，前缀尾回退，重复匹配，next[i] = next[j] + 1
        else
        {
            while (j != 0)
            {
                j = next[j - 1];
                if (needle[i] == needle[j])
                {
                    next[i] = next[j] + 1;
                    ++j;
                    break;
                }
            }
        }
            
    }
    return next;
}

int strStr(string haystack, string needle)
{
    vector<int> next = getNext(needle);
    int j = 0, i = 0;
     while (i < haystack.size() && j < needle.size())
    {
        if (haystack[i++] == needle[j])
            ++j;
        else
        {
            if ( j != 0)
            {
                j = next[j - 1];
                --i;
            }
        }
    }
    return j == needle.size() ? i - j : -1;
}

void solution(string &haystack, string &needle, int target)
{
    check(strStr(haystack, needle), target);
}

int main(int argc, char **argv)
{
    string haystack, needle;
    int target;

    // case 1
    haystack = "sadbutsad";
    needle = "sad";
    target = 0;
    solution(haystack, needle, target);

    // case 2
    haystack = "leetcode";
    needle = "leeto";
    target = -1;
    solution(haystack, needle, target);
}