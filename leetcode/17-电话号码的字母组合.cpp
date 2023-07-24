#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

unordered_map<char, string> dict = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                    {'8', "tuv"}, {'9', "wxyz"}};

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};
    vector<string> sub_combinations =
        letterCombinations(digits.substr(1, digits.size() - 1));
    vector<string> combinations;
    if (sub_combinations.size() == 0) sub_combinations = {""};
    for (char ch : dict[digits[0]]) {
        for (string &combination : sub_combinations)
            combinations.push_back(ch + combination);
    }
    return combinations;
}

int main(int argc, char **argv) {
    vector<string> combinations = letterCombinations("23");
}