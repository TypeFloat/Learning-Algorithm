#include "utils.h"

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> dict(26);
    for (char ch : magazine)
        ++dict[ch - 'a'];
    for (char ch : ransomNote)
    {
        if (dict[ch - 'a'] > 0)
            --dict[ch - 'a'];
        else
            return false;
    }
    return true;
}

void solution(string &ransomNode, string &magazine, bool target)
{
    check(canConstruct(ransomNode, magazine), target);
}

int main(int argc, char **argv)
{
    string ransomNode, magazine;
    bool target;

    // case 1
    ransomNode = "a";
    magazine = "b";
    target = false;
    solution(ransomNode, magazine, target);

    // case 2
    ransomNode = "aa";
    magazine = "ab";
    target = false;
    solution(ransomNode, magazine, target);

    // case 3
    ransomNode = "aa";
    magazine = "aab";
    target = true;
    solution(ransomNode, magazine, target);
}