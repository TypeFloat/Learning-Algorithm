#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        int circleCount = 0;
        int startX, startY, targetX, targetY;
        int tmpVal, count, step;
        while (circleCount < matrix.size() / 2) {
            startX = circleCount;
            startY = circleCount;
            targetX = circleCount;
            targetY = circleCount;
            count = max(1, static_cast<int>(
                               pow(matrix.size() - 2 * circleCount, 2) -
                               pow(matrix.size() - 2 * circleCount - 2, 2)));
            while (count > 0) {
                step = (matrix.size() - 1 - 2 * circleCount);
                tmpVal = matrix[startX][startY];
                do {
                    int localStep = step;
                    while (localStep--) {
                        if (targetX == circleCount &&
                            targetY < matrix.size() - circleCount - 1)
                            ++targetY;
                        else if (targetX < matrix.size() - circleCount - 1 &&
                                 targetY == matrix.size() - circleCount - 1)
                            ++targetX;
                        else if (targetX == matrix.size() - circleCount - 1 &&
                                 targetY > circleCount)
                            --targetY;
                        else if (targetY == circleCount &&
                                 targetX > circleCount)
                            --targetX;
                    }
                    swap(tmpVal, matrix[targetX][targetY]);
                    --count;
                } while (targetX != startX || targetY != startY);
                ++targetY;
                ++startY;
            }
            ++circleCount;
        }
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