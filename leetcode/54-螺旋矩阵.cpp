#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> rtn;
        int up = 0, down = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;
        while (up < down && left < right) {
            // up
            for (int i = left; i < right; ++i) rtn.push_back(matrix[up][i]);
            // right
            for (int i = up; i < down; ++i) rtn.push_back(matrix[i][right]);
            // down
            for (int i = right; i > left; --i) rtn.push_back(matrix[down][i]);
            // left
            for (int i = down; i > up; --i) rtn.push_back(matrix[i][left]);
            ++up;
            --down;
            ++left;
            --right;
        }
        if (up == down) {
            for (int i = left; i <= right; ++i) rtn.push_back(matrix[up][i]);
        } else if (left == right) {
            for (int i = up; i <= down; ++i) rtn.push_back(matrix[i][left]);
        }
        return rtn;
    }
};

void test(vector<vector<int>> &matrix, vector<int> &ans) {
    Solution solution = Solution();
    vector<int> rtn = solution.spiralOrder(matrix);
    ASSERT_EQ(rtn, ans);
}

TEST(Q54, CASE1) {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    test(matrix, ans);
}

TEST(Q54, CASE2) {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> ans = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    test(matrix, ans);
}

TEST(Q54, CASE3) {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    vector<int> ans = {1, 2, 3, 4, 8, 7, 6, 5};
    test(matrix, ans);
}