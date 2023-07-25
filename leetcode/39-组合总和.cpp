#include <atomic>
#include <vector>

#include "utils.h"

using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    if (target == 0) return {{}};
    if (target < 0) return {};
    vector<vector<int>> combinations;
    for (auto candidate = candidates.begin(); candidate != candidates.end();
         candidate++) {
        vector<int> sub_candidates(candidate, candidates.end());
        vector<vector<int>> sub_combinations =
            combinationSum(sub_candidates, target - *candidate);
        for (vector<int> combination : sub_combinations) {
            combination.push_back(*candidate);
            combinations.push_back(combination);
        }
    }
    return combinations;
}

int main(int argc, char **argv) {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = combinationSum(candidates, target);
}