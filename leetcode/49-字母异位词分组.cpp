#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> record;
        vector<vector<string>> rtn;
        for (string str : strs) {
            vector<int> count(26, 0);
            for (char ch : str) {
                count[ch - 'a']++;
            }
            string key = this->vector2hash(count);
            if (record.find(key) != record.end())
                record[key].push_back(str);
            else
                record[key] = {str};
        }
        for (auto [key, value] : record) {
            rtn.push_back(value);
        }
        return rtn;
    };

    string vector2hash(vector<int> &count) {
        string str = "";
        for (int i = 0; i < count.size(); ++i) {
            str += 'a' + i;
            str += to_string(count[i]);
        }
        return str;
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