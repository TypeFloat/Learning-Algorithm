#include <algorithm>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

vector<int> partitionLabels(string s) {
    vector<pair<int, int>> set(26, pair<int, int>{-1, -1});
    vector<int> count;
    for (int i = 0; i < s.size(); ++i) {
        if (set[s[i] - 'a'].first == -1) {
            set[s[i] - 'a'].first = i;
            set[s[i] - 'a'].second = i;
        } else
            set[s[i] - 'a'].second = i;
    }
    sort(set.begin(), set.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    });
    int first = -1, second = -1;
    for (auto dict = set.cbegin(); dict != set.cend(); ++dict) {
        if (dict->first == -1) continue;
        if (dict->first > second) {
            if (first != -1) count.push_back(second - first + 1);
            first = dict->first;
            second = dict->second;
        } else
            second = second > dict->second ? second : dict->second;
    }
    count.push_back(second - first + 1);
    return count;
}

void solution(string s, vector<int> target) {
    check(partitionLabels(s), target);
}

int main(int argc, char **argv) {
    string s;
    vector<int> target;

    // case 1
    s = "ababcbacadefegdehijhklij";
    target = {9, 7, 8};
    solution(s, target);

    // case 2
    s = "eccbbbbdec";
    target = {10};
    solution(s, target);

    // case 3
    s = "caedbdedda";
    target = {1, 9};
    solution(s, target);
}