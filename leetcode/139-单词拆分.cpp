#include <string>
#include <unordered_set>
#include <vector>

#include "utils.h"

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            string word = s.substr(j, i - j);
            if (dict.find(word) != dict.end() && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[dp.size() - 1];
}

void solution(string s, vector<string>& wordDict, bool target) {
    check(wordBreak(s, wordDict), target);
}

int main(int argc, char** argv) {
    vector<string> wordDict;
    string s;

    // case 1
    s = "leetcode";
    wordDict = {"leet", "code"};
    solution(s, wordDict, true);

    // case 2
    s = "applepenapple";
    wordDict = {"apple", "pen", "apple"};
    solution(s, wordDict, true);

    // case 3
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and"};
    solution(s, wordDict, false);
}