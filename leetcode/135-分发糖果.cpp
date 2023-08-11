#include <vector>

#include "utils.h"

using namespace std;

int candy(vector<int> &ratings) {
    vector<int> counts(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings[i] > ratings[i - 1])
            counts[i] = max(counts[i], counts[i - 1] + 1);
    }
    for (int i = ratings.size() - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1])
            counts[i] = max(counts[i], counts[i + 1] + 1);
    }
    int count = 0;
    for (int i = 0; i < ratings.size(); ++i) {
        count += counts[i];
    }
    return count;
}

void solution(vector<int> &ratings, int target) {
    check(candy(ratings), target);
}

int main(int argc, char **argv) {
    vector<int> ratings;

    // case 1
    ratings = {1, 0, 2};
    solution(ratings, 5);

    // case 2
    ratings = {1, 2, 2};
    solution(ratings, 4);

    // case 3
    ratings = {1, 3, 2, 2, 1};
    solution(ratings, 7);
}