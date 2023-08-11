#include <vector>

#include "utils.h"

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    });
    vector<int> null(2, -1);
    vector<vector<int>> queue(people.size(), null);
    for (auto person = people.begin(); person != people.end(); person++) {
        int next = (*person)[1];
        for (auto q = queue.begin(); q != queue.end(); q++) {
            if (*q == null) {
                if (next == 0) {
                    *q = *person;
                    break;
                } else
                    next--;
            } else if ((*q)[0] == (*person)[0])
                next--;
        }
    }
    return queue;
}

void solution(vector<vector<int>> &people, vector<vector<int>> &target) {
    check(reconstructQueue(people), target);
}

int main(int argc, char **argv) {
    vector<vector<int>> people, target;

    // case 1
    people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    target = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    solution(people, target);

    // case 2
    people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    target = {{4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0}};
    solution(people, target);
}