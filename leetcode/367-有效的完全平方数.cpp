#include "utils.h"


bool isPerfectSquare(int num)
{
    // 在数组搜索时的最小二乘，右侧为 len - 1，但此处不需要减一
    int left = 0, right = num;
    long int square, mid;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        // mid 就要使用长整形的原因是在乘法的运算过程中结果就可能出现了溢出，即要保证 mid * mid 是不会溢出的
        square = mid * mid;
        if (square == num)
            return true;
        else if (square < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main(int argc, char **argv)
{
    int num;
    bool target;

    // case1
    num = 16;
    target = true;
    cout << "Case 1: " << check(isPerfectSquare(num), target) << endl;

    // case2
    num = 14;
    target = false;
    cout << "Case 2: " << check(isPerfectSquare(num), target) << endl;
}