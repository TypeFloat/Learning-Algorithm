#include "utils.h"


vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size(), index = 0, top = 0, bottom = m - 1, left = 0, right = n - 1, row = -1, column = 0;
    vector<int> rtn(m*n);
    while (index < m * n)
    {
        // 上行
        while (row < right && index < m * n)
            rtn[index++] = matrix[column][++row];
        ++top;
        // 右列
        while (column < bottom && index < m * n)
            rtn[index++] = matrix[++column][row];
        --right;
        // 下行
        while (row > left && index < m * n)
            rtn[index++] = matrix[column][--row];
        --bottom;
        // 左列
        while (column > top && index < m * n)
            rtn[index++] = matrix[--column][row];
        ++left;
    }
    return rtn;
}

int main(int argc, char **argv)
{
    vector<vector<int>> matrix;
    vector<int> target;

    // case 1
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    target = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    check(target, spiralOrder(matrix));

    // case 2
    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    target = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    check(target, spiralOrder(matrix));
}