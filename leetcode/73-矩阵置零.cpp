#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>> &matrix) {
        // 比较简单的模拟题，问题是不能在遍历的同时更改数组，否则会改变判断的情况（原本不是0）
        // 所以需要预先遍历一遍数组，找到需要置为0的行和列，再做修改
        // 简单的情况就是拿两个数组保存一下，空间复杂度是O(m+n)
        // 我们可以拿数组的第一行和第一列作为这两个临时数组的替代
        // 因此可以在常数空间复杂度中解决该问题
        bool zeroFirstCol = false, zeroFirstRow = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                zeroFirstCol = true;
                break;
            }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                zeroFirstRow = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].size(); ++j) matrix[i][j] = 0;
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.size(); ++j) matrix[j][i] = 0;
            }
        }
        if (zeroFirstCol) {
            for (int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        }
        if (zeroFirstRow) {
            for (int i = 0; i < matrix[0].size(); ++i) matrix[0][i] = 0;
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

TEST(Q73, CASE4) {
    vector<vector<int>> matrix = {{0}, {1}};
    vector<vector<int>> ans = {{0}, {0}};
    test(matrix, ans);
}