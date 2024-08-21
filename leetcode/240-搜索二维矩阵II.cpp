#include <gtest/gtest.h>

#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {

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