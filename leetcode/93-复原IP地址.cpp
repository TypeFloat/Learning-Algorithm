#include <string>
#include <vector>

#include "utils.h"

using namespace std;

vector<string> recursive(string s, int times) {
    if (times == 0 && s.empty()) return {""};
    if (times == 0 && !s.empty()) return {};
    vector<string> combination;
    int num;
    if (s.size() >= 1) {
        num = s[0] - '0';
        for (string &sub_s : recursive(s.substr(1, s.size() - 1), times - 1)) {
            if (sub_s.size() != 0) {
                sub_s = to_string(num) + '.' + sub_s;
                combination.push_back(sub_s);
            } else {
                combination.push_back(to_string(num));
            }
        }

        if (s.size() >= 2 && num != 0) {
            num = num * 10 + s[1] - '0';
            for (string &sub_s :
                 recursive(s.substr(2, s.size() - 2), times - 1)) {
                if (sub_s.size() != 0) {
                    sub_s = to_string(num) + '.' + sub_s;
                    combination.push_back(sub_s);
                } else {
                    combination.push_back(to_string(num));
                }
            }

            if (s.size() >= 3) {
                num = num * 10 + s[2] - '0';
                if (num > 255) return combination;
                for (string &sub_s :
                     recursive(s.substr(3, s.size() - 3), times - 1)) {
                    if (sub_s.size() != 0) {
                        sub_s = to_string(num) + '.' + sub_s;
                        combination.push_back(sub_s);
                    } else {
                        combination.push_back(to_string(num));
                    }
                }
            }
        }
    }
    return combination;
}

vector<string> restoreIpAddresses(string s) { return recursive(s, 4); }

int main(int argc, char **argv) {
    string s = "127001";
    vector<string> ip = restoreIpAddresses(s);
}