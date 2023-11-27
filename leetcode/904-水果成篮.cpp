#include <gtest/gtest.h>

#include <vector>

using namespace std;

int totalFruit(vector<int> &fruits) {
    vector<int> kind(2, -1), num(2, 0);
    int max_num = 0;
    int left = 0;
    kind[0] = fruits[0];
    num[0] = 1;
    int index;
    for (int right = 1; right < fruits.size(); ++right) {
        if (kind[0] == fruits[right] || kind[1] == fruits[right]) {
            index = kind[0] == fruits[right] ? 0 : 1;
            num[index] += 1;
        } else if (num[0] == 0 || num[1] == 0) {
            index = num[0] == 0 ? 0 : 1;
            kind[index] = fruits[right];
            num[index] = 1;
        } else {
            max_num = max(max_num, num[0] + num[1]);
            while (!(num[0] == 0 || num[1] == 0)) {
                index = kind[0] == fruits[left] ? 0 : 1;
                num[index] -= 1;
                ++left;
            }
            index = num[0] == 0 ? 0 : 1;
            num[index] = 1;
            kind[index] = fruits[right];
        }
    }
    return max(max_num, num[0] + num[1]);
}

TEST(Q904, CASE1) {
    vector<int> fruits = {3, 1, 3, 2};
    ASSERT_EQ(totalFruit(fruits), 3);
}

TEST(Q904, CASE2) {
    vector<int> fruits = {0, 1, 2, 2};
    ASSERT_EQ(totalFruit(fruits), 3);
}

TEST(Q904, CASE3) {
    vector<int> fruits = {1, 2, 3, 2, 2};
    ASSERT_EQ(totalFruit(fruits), 4);
}

TEST(Q904, CASE4) {
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    ASSERT_EQ(totalFruit(fruits), 5);
}

TEST(Q904, CASE5) {
    vector<int> fruits = {0, 0, 1, 1};
    ASSERT_EQ(totalFruit(fruits), 4);
}

TEST(Q904, CASE6) {
    vector<int> fruits = {1, 0, 1, 4, 1, 4, 1, 2, 3};
    ASSERT_EQ(totalFruit(fruits), 5);
}