#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 else
                     return a[0] < b[0];
             });
        vector<vector<int>> rtn;
        int left = intervals[0][0], right = intervals[0][1];
        for (auto iter = intervals.begin() + 1; iter != intervals.end();
             ++iter) {
            if ((*iter)[0] > right) {
                rtn.push_back({left, right});
                left = (*iter)[0];
                right = (*iter)[1];
            } else
                right = max(right, (*iter)[1]);
        }
        rtn.push_back({left, right});
        return rtn;
    }
};

void test(vector<vector<int>> &intervals, vector<vector<int>> &ans) {
    Solution solution = Solution();
    vector<vector<int>> rtn = solution.merge(intervals);
    sort(rtn.begin(), rtn.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    sort(ans.begin(), ans.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    ASSERT_EQ(rtn, ans);
}

TEST(Q56, CASE1) {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = {{1, 6}, {8, 10}, {15, 18}};
    test(intervals, ans);
}

TEST(Q56, CASE2) {
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    vector<vector<int>> ans = {{1, 5}};
    test(intervals, ans);
}
