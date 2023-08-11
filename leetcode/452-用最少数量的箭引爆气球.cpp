#include <vector>

#include "utils.h"

using namespace std;

int findMinArrowShots(vector<vector<int>> &points) {
    int count = 1;
    sort(points.begin(), points.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    int pos = points[points.size() - 1][0];
    for (auto point = points.rbegin(); point != points.rend(); ++point) {
        if ((*point)[0] <= pos && pos <= (*point)[1]) {
            continue;
        } else {
            pos = (*point)[0];
            count++;
        }
    }
    return count;
}

void solution(vector<vector<int>> &points, int target) {
    check(findMinArrowShots(points), target);
}

int main(int argc, char **argv) {
    vector<vector<int>> points;

    // case 1
    points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    solution(points, 2);

    // case 2
    points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    solution(points, 4);

    // case 3
    points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    solution(points, 2);
}