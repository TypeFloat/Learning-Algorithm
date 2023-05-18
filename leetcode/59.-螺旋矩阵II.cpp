#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n));
    int index = 1, left = 0, top = 0, right = n - 1, bottom = n - 1, row = -1, column = 0;
    while (index <= n * n)
    {
        // 上行
        while (row < right && index <= n * n)
            matrix[column][++row] = index++;
        ++top;
        // 右列
        while (column < bottom && index <= n * n)
            matrix[++column][row] = index++;
        --right;
        // 下行
        while (row > left && index <= n * n)
            matrix[column][--row] = index++;
        --bottom;
        // 上行
        while (column > top && index <= n * n)
            matrix[--column][row] = index++;
        ++left;
    }
    return matrix;
}

int main(int argc, char **argv)
{
    int n;
    vector<vector<int>> target;

    // case 1
    n = 3;
    target = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    cout << "Case 1: " << check(generateMatrix(n), target) << endl;
    
    // case 2
    n = 1;
    target = {{1}};
    cout << "Case 2: " << check(generateMatrix(n), target) << endl;
}