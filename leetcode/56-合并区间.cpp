#include <algorithm>
#include <vector>

#include "utils.h"

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    int left = -1, right = -1;
    for (vector<int> &interval : intervals) {
        if (left == -1) {
            left = interval[0];
            right = interval[1];
        } else if (left <= interval[0] && interval[0] <= right)
            right = right > interval[1] ? right : interval[1];
        else {
            result.push_back({left, right});
            left = interval[0];
            right = interval[1];
        }
    }
    result.push_back({left, right});
    return result;
}

void solution(vector<vector<int>> &intervals, vector<vector<int>> &target) {
    check(merge(intervals), target);
}

int main(int argc, char **argv) {
    vector<vector<int>> intervals, target;

    // case 1
    intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    target = {{1, 6}, {8, 10}, {15, 18}};
    solution(intervals, target);

    // case 2
    intervals = {{1, 4}, {4, 5}};
    target = {{1, 5}};
    solution(intervals, target);
}