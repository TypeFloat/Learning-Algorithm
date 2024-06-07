#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>> &matrix) {
        int firstRow = 1, firstColumn = 1;
        int rows = matrix.size(), columns = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                firstColumn = 0;
                break;
            }
        }
        for (int i = 0; i < columns; ++i) {
            if (matrix[0][i] == 0) {
                firstRow = 0;
                break;
            }
        }
        for (int row = 1; row < rows; ++row) {
            for (int column = 1; column < columns; ++column) {
                if (matrix[row][column] == 0) {
                    matrix[0][column] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        for (int row = 1; row < rows; ++row) {
            if (matrix[row][0] == 0) {
                for (int column = 1; column < columns; ++column) {
                    matrix[row][column] = 0;
                }
            }
        }
        for (int column = 1; column < columns; ++column) {
            if (matrix[0][column] == 0) {
                for (int row = 1; row < rows; ++row) {
                    matrix[row][column] = 0;
                }
            }
        }
        if (firstColumn == 0) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }
        if (firstRow == 0) {
            for (int column = 0; column < columns; ++column) {
                matrix[0][column] = 0;
            }
        }
    }
};

void test(vector<vector<int>> &matrix, vector<vector<int>> &ans) {
    Solution solution = Solution();
    solution.setZeroes(matrix);
    ASSERT_EQ(matrix, ans);
}

TEST(Q73, CASE1) {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> ans = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    test(matrix, ans);
}

TEST(Q73, CASE2) {
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> ans = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    test(matrix, ans);
}

TEST(Q73, CASE3) {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    vector<vector<int>> ans = {
        {0, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    test(matrix, ans);
}