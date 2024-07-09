#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <functional>
#include <vector>

using namespace std;

void insertSort(vector<int> &nums) {}

void shellSort(vector<int> &nums) {}

void selectionSort(vector<int> &nums) {
    // 选择排序的原理是遍历当前数组，找到最大值
    // 将其交换到数组尾部，完成一次排序
    // 然后循环处理剩余数组
    // 重复n次可以完成排序，所以时间复杂度是(n^2)
    // 即使是有序的数组，也需要n次遍历，所以最优时间复杂度也是O(n^2)
    // 仅在交换元素和存储当前最大值的下标时使用了辅助空间，所以空间复杂度是O(1)
    int maxIdx;
    for (int i = nums.size() - 1; i >= 0; --i) {
        maxIdx = 0;
        for (int j = 1; j <= i; ++j) {
            // 在更新maxIdx时，无论是使用<还是<=，都无法实现稳定排序
            // 因为在交换元素的时候，没有考虑被交换元素的位置
            if (nums[maxIdx] < nums[j]) maxIdx = j;
        }
        swap(nums[i], nums[maxIdx]);
    }
}

void heapSort(vector<int> &nums) {}

void bubbleSort(vector<int> &nums) {
    // 冒泡排序的原理是一个数字会持续向后移动，直到遇到遇到比他更大的数
    // 然后这个更大的数再向后移动，
    // 直到最大的数移动到数组的尾部
    // 每次循环可以将一个最大的数移动至数组尾部
    // 重复上述循环n次可以完成排序，所以时间复杂度是O(n^2)
    // 最好情况下也需要进行n次比较，所以最优时间复杂度是O(n)
    // 仅在交换元素时使用了辅助空间，所以空间复杂度是O(1)
    for (int i = nums.size() - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            // 仅在前一个数绝对大的时候交换，所以冒泡排序是稳定的
            if (nums[j + 1] < nums[j]) swap(nums[j], nums[j + 1]);
        }
    }
}

void quickSort(vector<int> &nums) {}

void mergeSort(vector<int> &nums) {}

void countSort(vector<int> &nums) {}

void bucketSort(vector<int> &nums) {}

void radixSort(vector<int> &nums) {}

void test(std::function<void(vector<int> &)> sortFunc) {
    vector<int> nums(1000, 0);
    for (int i = 0; i < 1000; ++i) {
        nums[i] = random() % 2048;
    }
    vector<int> ans = nums;
    sort(ans.begin(), ans.end());
    sortFunc(nums);
    ASSERT_EQ(nums, ans);
}

TEST(Sort, Insert) { test(insertSort); }

TEST(Sort, Shell) { test(shellSort); }

TEST(Sort, Selection) { test(selectionSort); }

TEST(Sort, Heap) { test(heapSort); }

TEST(Sort, Bubble) { test(bubbleSort); }

TEST(Sort, Quick) { test(quickSort); }

TEST(Sort, Merge) { test(mergeSort); }

TEST(Sort, Count) { test(countSort); }

TEST(Sort, Bucket) { test(bucketSort); }

TEST(Sort, Radix) { test(radixSort); }