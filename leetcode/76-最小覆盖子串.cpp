#include "utils.h"


string minWindow(string s, string t)
{
    unordered_map<char, int> dict;
    // 构建目标串字典
    for (char ch : t)
    {
        if (dict.find(ch) == dict.end())
            dict[ch] = 1;
        else
            dict[ch] += 1;
    }
    int minLeft = -1, minRight = -1, minStrLen = s.size() + 1, left = 0, right = -1, charSum = t.size();
    // 找到第一个串
    while (charSum != 0)
    {
        ++right;
        if (right >= s.size())
            return "";
        if (dict.find(s[right]) != dict.end())
        {
            if (dict[s[right]] > 0)
                charSum -= 1;
            dict[s[right]] -= 1;
        }
    }
    // 继续寻找更优串
    while (right < s.size())
    {
        // 优化子串
        while (true)
        {
            if (dict.find(s[left]) != dict.end())
            {
                if (dict[s[left]] == 0)
                    break;
                else
                    dict[s[left]] += 1;
            }
            ++left;
        }
        if (minStrLen > right - left + 1)
        {
            minStrLen = right - left + 1;
            minLeft = left;
            minRight = right;
        }
        ++right;
        if (dict.find(s[right]) != dict.end())
            dict[s[right]] -= 1;
    }

    return string(s.begin() + minLeft, s.begin() + minRight + 1);
}

int main(int argc, char **argv)
{
    string s, t, target;

    // case 1
    s = "ADOBECODEBANC";
    t = "ABC";
    target = "BANC";
    check(target, minWindow(s, t));

    // case 2
    s = "a";
    t = "a";
    target = "a";
    check(target, minWindow(s, t));

    // case 3
    s = "a";
    t = "aa";
    target = "";
    check(target, minWindow(s, t));
}