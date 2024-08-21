#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        // 纯纯的模拟问题，没什么算法，纯编程能力的考察
        for (int i = 0; i < matrix.size() / 2; ++i) {
            for (int j = i; j < matrix.size() - i - 1; ++j) {
                int row = i, col = j, tmp = matrix[row][col];
                int direction = 0;
                do {
                    pair<int, int> next =
                        convert(row, col, matrix.size() - 2 * i, matrix.size(),
                                direction);
                    row = next.first;
                    col = next.second;
                    swap(tmp, matrix[row][col]);

                } while (row != i || col != j);
            }
        }
    }

    pair<int, int> convert(int row, int col, int size, int maxSize,
                           int &direction) {
        int count = size - 1;
        int minRange = (maxSize - size) / 2;
        int maxRange = (maxSize + size) / 2 - 1;
        while (count) {
            if (direction == 0) {
                while (count && col < maxRange) {
                    ++col;
                    --count;
                }
                if (count != 0)
                    ++direction;
                else
                    return {row, col};
            }
            if (direction == 1) {
                while (count && row < maxRange) {
                    ++row;
                    --count;
                }
                if (count != 0)
                    ++direction;
                else
                    return {row, col};
            }
            if (direction == 2) {
                while (count && col > minRange) {
                    --col;
                    --count;
                }
                if (count != 0)
                    ++direction;
                else
                    return {row, col};
            }
            if (direction == 3) {
                while (count && row > minRange) {
                    --row;
                    --count;
                }
                if (count != 0)
                    direction = 0;
                else
                    return {row, col};
            }
        }
        return {row, col};
    }
};

void test(vector<vector<int>> &matrix, vector<vector<int>> &ans) {
    Solution solution = Solution();
    solution.rotate(matrix);
    ASSERT_EQ(matrix, ans);
}

TEST(Q48, CASE1) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> ans = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    test(matrix, ans);
}

TEST(Q48, CASE2) {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    vector<vector<int>> ans = {
        {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    test(matrix, ans);
}