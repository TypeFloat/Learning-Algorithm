#include <string>
#include <system_error>

#include "utils.h"

using namespace std;

void altivate(string::iterator begin, string::iterator end, char val) {
    while (begin != end) {
        *begin = val;
        begin++;
    }
}

int monotoneIncreasingDigits(int n) {
    string n_s = to_string(n);
    if (n_s.size() == 1) return n;
    int left, max_val = -1;
    for (string::iterator iter = n_s.begin(); iter != n_s.end(); ++iter) {
        int val = *iter - '0';
        if (val > max_val) {
            max_val = val;
            left = iter - n_s.begin();
        } else if (val == max_val)
            continue;
        else {
            altivate(n_s.begin() + left, n_s.begin() + left + 1,
                     static_cast<char>(max_val - 1 + '0'));
            altivate(n_s.begin() + left + 1, n_s.end(), static_cast<char>('9'));

            break;
        }
    }
    return stoi(n_s);
}

void solution(int n, int target) { check(monotoneIncreasingDigits(n), target); }

int main(int argc, char **argv) {
    // case 1
    solution(10, 9);

    // case 2
    solution(1234, 1234);

    // case 3
    solution(332, 299);

    // case 4
    solution(120, 119);
}