#include <algorithm>
#include <vector>

#include "utils.h"

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) {
             return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
         });
    int count = 0;
    for (auto ptr = intervals.rbegin(); ptr != intervals.rend() - 1; ++ptr) {
        if ((*ptr)[0] < (*(ptr + 1))[1]) {
            count += 1;
            *(ptr + 1) = *ptr;
        }
    }
    return count;
}

void solution(vector<vector<int>> &intervals, int target) {
    check(eraseOverlapIntervals(intervals), target);
}

int main(int argc, char **argv) {
    vector<vector<int>> intervals;

    // case 1
    intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    solution(intervals, 1);

    // case 2
    intervals = {{1, 2}, {1, 2}, {1, 2}};
    solution(intervals, 2);

    // case 3
    intervals = {{1, 2}, {2, 3}};
    solution(intervals, 0);

    // cas4 4
    intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    solution(intervals, 2);
}