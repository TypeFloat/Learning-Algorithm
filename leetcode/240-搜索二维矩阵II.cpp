#include <gtest/gtest.h>

#include <memory>
#include <regex>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int left = 0, right = matrix[0].size() - 1, up = 0,
            down = matrix.size() - 1, mid, count = 0;
        while (1) {
            if (left > right) break;
            while (left <= right) {
                mid = (right + left) / 2;
                if (matrix[up][mid] == target) {
                    return true;
                } else if (matrix[up][mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (matrix[up][mid] > target)
                right = mid - 1;
            else
                right = mid;
            left = count;
            ++up;

            if (up > down) break;
            while (up <= down) {
                mid = (up + down) / 2;
                if (matrix[mid][left] == target) {
                    return true;
                } else if (matrix[mid][left] < target) {
                    up = mid + 1;
                } else {
                    down = mid - 1;
                }
            }
            if (matrix[mid][left] > target)
                down = mid - 1;
            else
                down = mid;
            up = count + 1;
            ++left;
            ++count;
        }
        return false;
    }
};

void test(vector<vector<int>> &matrix, int taget, bool ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.searchMatrix(matrix, taget), ans);
}

TEST(Q240, CASE1) {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 5;
    bool ans = true;
    test(matrix, target, ans);
}

TEST(Q240, CASE2) {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 20;
    bool ans = false;
    test(matrix, target, ans);
}

TEST(Q240, CASE3) {
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25}};
    int target = 19;
    bool ans = true;
    test(matrix, target, ans);
}

TEST(Q240, CASE4) {
    vector<vector<int>> matrix = {{1, 1}};
    int taget = 2;
    bool ans = false;
    test(matrix, taget, ans);
}