#include <gtest/gtest.h>
#include <sys/syslimits.h>

#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int up = 0, down = matrix.size() - 1, left = 0,
        right = matrix[0].size() - 1;
    int index = 0;
    vector<int> rtn(matrix.size() * matrix[0].size());
    while (up < down && left < right) {
        // 处理上边界
        for (int i = left; i < right; ++i) {
            rtn[index++] = matrix[up][i];
        }
        // 处理右边界
        for (int i = up; i < down; ++i) {
            rtn[index++] = matrix[i][right];
        }
        // 处理下边界
        for (int i = right; i > left; --i) {
            rtn[index++] = matrix[down][i];
        }
        // 处理左边届
        for (int i = down; i > up; --i) {
            rtn[index++] = matrix[i][left];
        }
        ++up;
        --right;
        --down;
        ++left;
    }
    if (index > rtn.size() - 1) return rtn;
    if (up == down) {
        for (int i = left; i <= right; ++i) {
            rtn[index++] = matrix[up][i];
        }
    } else {
        for (int i = up; i <= down; ++i) {
            rtn[index++] = matrix[i][left];
        }
    }
    return rtn;
}

TEST(Q54, CASE1) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> target = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    ASSERT_EQ(spiralOrder(matrix), target);
}

TEST(Q54, CASE2) {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> target = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    ASSERT_EQ(spiralOrder(matrix), target);
}

TEST(Q54, CASE3) {
    vector<vector<int>> matrix = {{1, 11}, {2, 12}, {3, 13}, {4, 14}, {5, 15},
                                  {6, 16}, {7, 17}, {8, 18}, {9, 19}, {10, 20}};
    vector<int> target = {1,  11, 12, 13, 14, 15, 16, 17, 18, 19,
                          20, 10, 9,  8,  7,  6,  5,  4,  3,  2};
    ASSERT_EQ(spiralOrder(matrix), target);
}