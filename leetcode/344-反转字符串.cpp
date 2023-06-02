#include "utils.h"

using namespace std;

void reverseString(vector<char> &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
        swap(s[left++], s[right--]);
}

void solution(vector<char> &s)
{
    vector<char> t = s;
    reverse(t.begin(), t.end());
    reverseString(s);
    check(s, t);
}

int main(int argc, char **argv)
{
    vector<char> s;
    
    // case 1
    s = {'h', 'e', 'l', 'l', 'o'};
    solution(s);

    // case 2
    s = {'h', 'a', 'n', 'n', 'a', 'h'};
    solution(s);
}