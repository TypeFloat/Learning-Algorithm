#include "utils.h"

using namespace std;

string reverseLeftWords(string s, int n)
{
    return s.substr(n, s.size()-n) + s.substr(0, n);
}

void solution(string &s, int n, string &t)
{
    check(reverseLeftWords(s, n), t);
}

int main(int argc, char **argv)
{
    string s, t;
    int n;

    // case 1
    s = "abcdefg";
    t = "cdefgab";
    n = 2;
    solution(s, n, t);

    // case 2
    s = "lrloseumgh";
    t = "umghlrlose";
    n = 6;
    solution(s, n, t);
}