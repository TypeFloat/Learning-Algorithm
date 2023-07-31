#include <vector>

#include "utils.h"

using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    if (nums.size() == 0) return {{}};
    vector<int> sub_nums = vector<int>(nums.begin() + 1, nums.end());
    vector<vector<int>> sets = subsets(sub_nums);
    int size = sets.size();
    for (int i = 0; i < size; ++i) {
        vector<int> set = sets[i];
        set.insert(set.begin(), nums[0]);
        sets.push_back(set);
    }
    return sets;
}

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sets = subsets(nums);
}
