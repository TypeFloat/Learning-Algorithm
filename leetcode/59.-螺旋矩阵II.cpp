#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n, 0));
    int column_min = 0, row_min = 0, column, row;
    int index = 1, flag;
    // 偶数列和奇数列的处理不一样
    if (n % 2 == 0)
        flag = n * n + 1;
    else
        flag = n * n;
    while (index < flag)
    {
        column = column_min;
        row = row_min;
        // 上行
        while (row < n - row_min - 1)
            matrix[column][row++] = index++;
        // 右列
        while (column < n - column_min - 1)
            matrix[column++][row] = index++;
        // 下行
        while (row >= row_min + 1)
            matrix[column][row--] = index++;
        // 左列
        while (column >= column_min + 1)
            matrix[column--][row] = index++;
        column_min++;
        row_min++;
    }
    // 奇数列的中心数单独赋值
    if (n % 2 != 0)
        matrix[n/2][n/2] = index;
    return matrix;
}

int main(int argc, char **argv)
{
    int n;
    vector<vector<int>> target;

    // case 1
    n = 3;
    target = vector<vector<int>>{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    cout << "Case 1: " << check(generateMatrix(n), target) << endl;
    
    // case 2
    n = 1;
    target = vector<vector<int>>{{1}};
    cout << "Case 2: " << check(generateMatrix(n), target) << endl;
}