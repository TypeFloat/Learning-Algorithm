#include <algorithm>
#include <vector>

#include "utils.h"

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j++]) i++;
    }
    return i;
}

void solution(vector<int> &g, vector<int> &s, int target) {
    check(findContentChildren(g, s), target);
}

int main(int argc, char **argv) {
    vector<int> g, s;
    int target;

    // case 1
    g = {1, 2, 3};
    s = {1, 1};
    target = 1;
    solution(g, s, target);

    // case 2
    g = {1, 2};
    s = {1, 2, 3};
    target = 2;
    solution(g, s, target);

    // case
    g = {10, 9, 8, 7};
    s = {5, 6, 7, 8};
    target = 2;
    solution(g, s, target);
}