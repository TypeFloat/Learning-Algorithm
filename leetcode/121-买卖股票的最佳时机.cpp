#include <vector>

#include "utils.h"

using namespace std;

int maxProfit(vector<int> &prices) {
    int low = 10e4;
    int profit = 0;
    for (int price : prices) {
        low = min(low, price);
        profit = max(profit, price - low);
    }
    return profit;
}

void solution(vector<int> &prices, int target) {
    check(maxProfit(prices), target);
}

int main(int argc, char **argv) {
    vector<int> prices;

    // case 1
    prices = {7, 1, 5, 3, 6, 4};
    solution(prices, 5);

    // case 2
    prices = {7, 6, 4, 3, 1};
    solution(prices, 0);
}