#include <algorithm>
#include <string>
#include <vector>

#include "utils.h"

using namespace std;

bool isValid(string s) {
    if (s.size() <= 1) return true;
    return s[0] == s[s.size() - 1] && isValid(s.substr(1, s.size() - 2));
}

vector<vector<string>> partition(string s) {
    if (s.size() == 0) return {{}};
    if (s.size() == 1) return {{s}};
    vector<vector<string>> partitions;
    for (int i = 1; i <= s.size(); ++i) {
        if (isValid(s.substr(0, i))) {
            vector<vector<string>> sub_partition =
                partition(s.substr(i, s.size() - i));
            for (vector<string> &par : sub_partition) {
                par.insert(par.begin(), s.substr(0, i));
                partitions.push_back(par);
            }
        }
    }
    return partitions;
}

int main(int argc, char **argv) {
    string s = "bb";
    vector<vector<string>> partitions = partition(s);
}