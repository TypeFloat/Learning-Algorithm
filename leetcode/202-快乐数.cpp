#include "utils.h"

using namespace std;

bool isHappy(int n)
{
    unordered_set<int> record;
    string numStr;
    while (record.find(n) == record.end())
    {
        record.insert(n);
        numStr = to_string(n);
        n = 0;
        for (char ch : numStr)
            n += (ch - '0') * (ch - '0');
    }
    return n == 1 ? true : false;
}

void solution(int n, bool target)
{
    check(isHappy(n), target);
}

int main(int argc, char **argv)
{
    bool target;
    int n;

    // case 1
    n = 19;
    target = true;
    solution(n, target);

    // case 2
    n = 2;
    target = false;
    solution(n, target);
}