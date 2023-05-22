#include "utils.h"


int totalFruit(vector<int> &fruits)
{
    vector<int> fruitsCount = vector<int>(2), fruitsType = vector<int>(2, -1);
    int left = 0, right = 0, maxFruits = 0, fruitBucket;
    for (right = 0; right < fruits.size(); ++right)
    {
        // 如果是一种新水果，放入一个空框或者空出一个框
        if (fruits[right] != fruitsType[0] && fruits[right] != fruitsType[1])
        {
            if (fruitsCount[0] == 0 || fruitsCount[1] == 0)
            {
                fruitBucket = fruitsCount[0] == 0 ? 0 : 1;
                fruitsType[fruitBucket] = fruits[right];
                fruitsCount[fruitBucket]++;
            }
            else
            {
                while (fruitsCount[0] != 0 && fruitsCount[1] != 0)
                {
                    fruitBucket = fruits[left++] == fruitsType[0] ? 0 : 1;
                    fruitsCount[fruitBucket]--;
                }
                fruitsType[fruitBucket] = fruits[right];
                fruitsCount[fruitBucket]++;
            }
        }
        else
        {
            fruitBucket = fruits[right] == fruitsType[0] ? 0 : 1;
            fruitsCount[fruitBucket]++;
        }
        maxFruits = max(maxFruits, right - left + 1);
    }
    return maxFruits;
}

int main(int argc, char **argv)
{
    vector<int> fruits;
    int target;

    // case 1
    fruits = vector<int>{3, 1, 3, 2};
    target = 3;
    check(target, totalFruit(fruits));

    // case 2
    fruits = vector<int>{0, 1, 2, 2};
    target = 3;
    check(target, totalFruit(fruits));

    // case 3
    fruits = vector<int>{1, 2, 3, 2, 2};
    target = 4;
    check(target, totalFruit(fruits));

    // case 4
    fruits = vector<int>{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    target = 5;
    check(target, totalFruit(fruits));
}