#include "utils.h"

using namespace std;

bool isAnagram(string s, string t)
{
    vector<int> count(26, 0);
    for (char ch : s)
        count[ch - 'a']++;
    for (char ch : t)
        count[ch - 'a']--;
    for (int val : count)
    {
        if (val != 0)
            return false;
    }
    return true;
}

void solution(string &s, string &t, bool target)
{
    check(isAnagram(s, t), target);
}

int main(int argc, char **argv)
{
    string s, t;
    bool target;

    // case 1
    s = "anagram";
    t = "nagaram";
    target = true;
    solution(s, t, target);

    // case 2
    s = "rat";
    t = "car";
    target = false;
    solution(s, t, target);
}