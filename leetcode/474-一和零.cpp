#include <string>
#include <type_traits>
#include <vector>

#include "utils.h"

using namespace std;

int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<vector<int>>> dp(
        strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 0; i < strs.size(); ++i) {
        for (int j = 0; j < m + 1; ++j) {
            for (int k = 0; k < n + 1; ++k) {
                int zero_count = 0, one_count = 0;
                for (char num : strs[i]) {
                    if (num == '0')
                        ++zero_count;
                    else
                        ++one_count;
                }
                if (zero_count <= j && one_count <= k) {
                    if (i > 0)
                        dp[i][j][k] =
                            dp[i - 1][j][k] >
                                    dp[i - 1][j - zero_count][k - one_count] + 1
                                ? dp[i - 1][j][k]
                                : dp[i - 1][j - zero_count][k - one_count] + 1;
                    else
                        dp[i][j][k] = 1;
                } else {
                    if (i > 0) dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }
    return dp[strs.size() - 1][m][n];
}

void solution(vector<string> &strs, int m, int n, int target) {
    check(findMaxForm(strs, m, n), target);
}

int main(int argc, char **argv) {
    vector<string> strs;

    // case 1
    strs = {"10", "0001", "111001", "1", "0"};
    solution(strs, 5, 3, 4);

    // case 2
    strs = {"10", "0", "1"};
    solution(strs, 1, 1, 2);
}