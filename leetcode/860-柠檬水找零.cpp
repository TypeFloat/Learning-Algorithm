#include <vector>

#include "utils.h"

using namespace std;

bool lemonadeChange(vector<int> &bills) {
    int num_of_five = 0, num_of_ten = 0, num_of_twenty = 0;
    for (int bill : bills) {
        if (bill == 5) {
            num_of_five += 1;
        } else if (bill == 10) {
            num_of_ten += 1;
            num_of_five -= 1;
            if (num_of_five < 0) return false;
        } else {
            if (num_of_ten > 0) {
                num_of_ten -= 1;
                num_of_five -= 1;
            } else
                num_of_five -= 3;
            if (num_of_five < 0) return false;
        }
    }
    return true;
}

void solution(vector<int> &bills, bool target) {
    check(lemonadeChange(bills), target);
}

int main(int argc, char **argv) {
    vector<int> bills;
    // case 1
    bills = {5, 5, 5, 10, 20};
    solution(bills, true);

    // case 2
    bills = {5, 5, 10, 10, 20};
    solution(bills, false);
}