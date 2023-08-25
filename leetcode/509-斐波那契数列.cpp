#include <vector>

#include "utils.h"

using namespace std;

int fib(int n) {
    static vector<int> dict(31, 0);
    if (n == 0 || n == 1)
        return n;
    else {
        if (dict[n] == 0) dict[n] = fib(n - 1) + fib(n - 2);
        return dict[n];
    }
}

void solution(int n, int target) { check(fib(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(2, 1);

    // case 2
    solution(3, 2);

    // case 3
    solution(4, 3);
}