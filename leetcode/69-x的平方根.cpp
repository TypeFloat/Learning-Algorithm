#include "utils.h"

int mySqrt(int x)
{
    // 乘方运算时可能导致溢出，因此要用长整形
    long int left = 0, right = x, mid, res_1, res_2;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        res_1 = mid * mid;
        res_2 = (mid + 1) * (mid + 1);
        if (res_2 <= x)
            left = mid + 1;
        else if (res_1 > x)
            right = mid - 1;
        else
            return mid;
    }
    return 0;
}

void solution(int x, int output)
{
    check(mySqrt(x), output);
}

int main(int argc, char **argv)
{
    int x, output;

    // case 1
    x = 4;
    output = 2;
    solution(x, output);

    // case 2
    x = 8;
    output = 2;
    solution(x, output);
}