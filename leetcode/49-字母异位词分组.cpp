#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // 使用字母出现次数作为哈希值，用字典进行统计即可，关键在于下民啊的strToHash
        unordered_map<string, vector<string>> record;
        for (string &str : strs) {
            string hash = this->strToHash(str);
            record[hash].push_back(str);
        }
        vector<vector<string>> rtn;
        for (auto iter = record.begin(); iter != record.end(); ++iter)
            rtn.push_back(iter->second);
        return rtn;
    }

    string strToHash(string &str) {
        vector<int> counter(26, 0);
        for (char ch : str) {
            counter[ch - 'a']++;
        }
        string hash = "";
        for (int num : counter)
            hash += (to_string(num) + ":");
        return hash;
    }
};

void test(vector<string> &strs, vector<vector<string>> &ans) {
    Solution solution = Solution();
    vector<vector<string>> rtn = solution.groupAnagrams(strs);
    ASSERT_EQ(rtn.size(), ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        sort(rtn[i].begin(), rtn[i].end(),
             [](string &a, string &b) { return a < b; });
        sort(ans[i].begin(), ans[i].end(),
             [](string &a, string &b) { return a < b; });
    }
    for (vector<vector<string>>::iterator iter = rtn.begin(); iter != rtn.end();
         ++iter) {
        for (vector<vector<string>>::iterator tmp = ans.begin();
             tmp != ans.end(); ++tmp) {
            if (*iter == *tmp) {
                ans.erase(tmp);
                break;
            }
        }
    }
    ASSERT_EQ(ans.size(), 0);
}

TEST(Q49, CASE1) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = {
        {"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    test(strs, ans);
}

TEST(Q49, CASE2) {
    vector<string> strs = {""};
    vector<vector<string>> ans = {{""}};
    test(strs, ans);
}

TEST(Q49, CASE3) {
    vector<string> strs = {"a"};
    vector<vector<string>> ans = {{"a"}};
    test(strs, ans);
}