#include <gtest/gtest.h>

#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int> &nums) {
        // 思路很简单，对数组排序后，遍历一遍即可得到答案
        // 但是要求时间复杂度O(n)，因此不能使用非线性时间的排序方法
        // 测试用例中有一个极端情况导致计数排序失效，发现排序的方法并不奏效
        // 转而使用哈希表
        // 在使用哈希表的时候也需要注意剪枝，防止超时
        unordered_set<int> record;
        for (int num : nums) {
            record.insert(num);
        }
        int num, localLength = 0, maxLength = 0;
        for (int iter : record) {
            if (record.find(iter + 1) != record.end()) continue;
            else {
                localLength = 1;
                num = iter - 1;
                while (record.find(num) != record.end()) {
                    ++localLength;
                    --num;
                }
                maxLength = max(maxLength, localLength);
            }
        }
        return maxLength;
    }
};

void test(vector<int> &nums, int target) {
    Solution solution = Solution();
    ASSERT_EQ(solution.longestConsecutive(nums), target);
};

TEST(Q128, CASE1) {
    vector<int> nums = {100, 4, 200, 1, 2, 3};
    int target = 4;
    test(nums, target);
}

TEST(Q128, CASE2) {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int target = 9;
    test(nums, target);
}