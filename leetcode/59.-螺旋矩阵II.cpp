#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int up = 0, down = n - 1, left = 0, right = n - 1;
    int index = 1;
    while (up < down && left < right) {
        // 处理上边界
        for (int i = left; i < right; ++i) {
            matrix[up][i] = index++;
        }
        // 处理右边界
        for (int i = up; i < down; ++i) {
            matrix[i][right] = index++;
        }
        // 处理下边界
        for (int i = right; i > left; --i) {
            matrix[down][i] = index++;
        }
        // 处理左边届
        for (int i = down; i > up; --i) {
            matrix[i][left] = index++;
        }
        ++up;
        --right;
        --down;
        ++left;
    }
    if (n % 2 != 0) {
        int ptr = (n - 1) / 2;
        matrix[ptr][ptr] = index;
    }
    return matrix;
}

TEST(Q59, CASE1) {
    vector<vector<int>> target = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    ASSERT_EQ(generateMatrix(3), target);
}

TEST(Q59, CASE2) {
    vector<vector<int>> target = {{1}};
    ASSERT_EQ(generateMatrix(1), target);
}

TEST(Q59, CASE3) {
    vector<vector<int>> target = {{1, 2}, {4, 3}};
    ASSERT_EQ(generateMatrix(2), target);
}

TEST(Q59, CASE4) {
    vector<vector<int>> target = {
        {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    ASSERT_EQ(generateMatrix(4), target);
}