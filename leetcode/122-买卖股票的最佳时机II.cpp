#include <queue>
#include <vector>

#include "utils.h"

using namespace std;

int maxProfit(vector<int>& prices) {
    int index = 0;
    while (index < prices.size() - 1 && prices[index] >= prices[index + 1])
        index++;
    if (prices.size() - index <= 1) return 0;
    int count = 0;
    int price = prices[index];
    bool isUp = true;
    for (auto num = prices.begin() + index + 1; num != prices.end(); ++num) {
        if (isUp && *num < *(num - 1)) {
            isUp = false;
            count += (*(num - 1) - price);
        }
        if (!isUp && *num > *(num - 1)) {
            isUp = true;
            price = *(num - 1);
        }
    }
    if (isUp) count += (prices[prices.size() - 1] - price);
    return count;
}

void solution(vector<int>& prices, int target) {
    check(maxProfit(prices), target);
}

int main(int argc, char** argv) {
    vector<int> prices;

    // case 1
    prices = {7, 1, 5, 3, 6, 4};
    solution(prices, 7);

    // case 2
    prices = {1, 2, 3, 4, 5};
    solution(prices, 4);

    // case 3
    prices = {7, 6, 4, 3, 1};
    solution(prices, 0);
}