#include <gtest/gtest.h>
#include <vector>

using namespace std;


class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> record(26, vector<int>(2, -1));
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (record[idx][0] == -1) {
                record[idx][0] = i;
                record[idx][1] = i;
            } else
                record[idx][1] = i;
        }
        sort(record.begin(), record.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        });
        vector<int> rtn;
        int left = -1, right = -1;
        for (vector<int> &iter : record) {
            if (iter[0] == -1)
                continue;
            else if (left == -1) {
                left = iter[0];
                right = iter[1];
            } else {
                if (right < iter[0]) {
                    rtn.push_back(right - left + 1);
                    left = iter[0];
                    right = iter[1];
                } else
                    right = max(right, iter[1]);
            }
        }
        rtn.push_back(right - left + 1);
        return rtn;
    }
};

void test(string &s, vector<int> &ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.partitionLabels(s), ans);
}

TEST(Q763, CASE1) {
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = {9, 7, 8};
    test(s, ans);
}