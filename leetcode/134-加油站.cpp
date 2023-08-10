#include <vector>

#include "utils.h"

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int count = 0, local_count = 0, start = 0;
    for (int i = 0; i < gas.size(); ++i) {
        int tmp = gas[i] - cost[i];
        local_count += tmp;
        count += tmp;
        if (local_count < 0) {
            local_count = 0;
            start = i + 1;
        }
    }
    if (count < 0) return -1;
    return start;
}

void solution(vector<int> &gas, vector<int> &cost, int target) {
    check(canCompleteCircuit(gas, cost), target);
}

int main(int argc, char **argv) {
    vector<int> gas, cost;

    // case 1
    gas = {1, 2, 3, 4, 5};
    cost = {3, 4, 5, 1, 2};
    solution(gas, cost, 3);

    // case 2
    gas = {2, 3, 4};
    cost = {3, 4, 3};
    solution(gas, cost, -1);
}