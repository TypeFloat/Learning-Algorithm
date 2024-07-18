#include <__type_traits/is_swappable.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <climits>
#include <functional>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

void insertSort(vector<int> &nums) {
    // 插入排序的原理是认为数组首部是有序的
    // 在有序数组中查找当前元素应该存在的位置，进行插入
    // 通过n次循环完成排序，每次循环时遍历有序数组，时间复杂度为O(n^2)
    // 在最好情况下，当前元素只需要与有序数组的末尾元素比较就可以确定插入位置，
    // 因此最优时间复杂度为O(n)
    // 仅在交换元素时使用了辅助空间，所以空间复杂度为O(1)
    // 在寻找插入时，是从后往前遍历，可以保证元素的相对顺序，因此是稳定的排序算法
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = i; j >= 1; --j) {
            if (nums[j] < nums[j - 1])
                swap(nums[j], nums[j - 1]);
            else
                break;
        }
    }
}

void shellSort(vector<int> &nums) {
    // 希尔排序是对插入排序的改进，采用类似于分治的方法降低排序时的比较次数，从而进行加速
    // 它的时间复杂度是O(nlogn)，最优时间复杂度、最差时间复杂度、空间复杂度与插入排序一致
    // 但是希尔排序是一种不稳定的排序，因为它进行了分组比较，分组可能导致不稳定
    int gap = nums.size() / 2;
    while (gap != 0) {
        for (int i = gap; i < 2 * gap; ++i) {
            for (int j = i; j < nums.size(); j += gap) {
                for (int k = j; k >= i % gap + 1; k -= gap) {
                    if (nums[k] < nums[k - gap])
                        swap(nums[k], nums[k - gap]);
                    else
                        break;
                }
            }
        }
        gap /= 2;
    }
}

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

void heapSort(vector<int> &nums) {
    // 堆排序是利用数据结构堆进行排序的一种算法
    // 堆分为大根堆和小根堆，大根堆中的每一棵子树的根节点都比其子节点的值大，小根堆反之
    // 大根堆本身是一棵完全二叉树，因此在排序时不需要真实的建立一棵数，可以利用完全二叉树每层节点数量的性质
    // 例如，大根堆要满足的条件是 arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]
    // 堆排序在排序时平均、最好、最差时间复杂度都是O(nlogn)
    // 不需要借助辅助空间，因此空间复杂度是O(1)
    // 是一种不稳定的排序算法
    int rootIdx, tmpIdx;
    for (int i = nums.size() - 1; i >= 0; --i) {
        for (int j = i; j > 0; --j) {
            // 重建大根堆
            // 当前节点是右节点
            if (j % 2 != 0) {
                rootIdx = (j - 1) / 2;
                tmpIdx = nums[j - 1] > nums[j] ? j - 1 : j;
                --j;
            } else {
                rootIdx = j / 2;
                tmpIdx = j;
            }
            if (nums[rootIdx] < nums[tmpIdx]) swap(nums[rootIdx], nums[tmpIdx]);
        }
        // 此时数组最大元素出现在根节点，交换根节点与最后一个节点
        swap(nums[0], nums[i]);
    }
}

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

void quickSort(vector<int> &nums) {
    // 快速排序的思想比较简单，但是实现上比较复杂
    // 其思想是选出一个哨兵元素，然后比该元素小的放在左边，大的放在右边
    // 此时哨兵元素的位置是正确的了
    // 然后依次递归左右两侧的元素
    // 其平均复杂度和最优复杂度是O(nlogn)，最坏情况出现在数据最初就是有序的情况，此时是O(n^2)
    // 空间复杂度是O(1)
    stack<pair<int, int>> sortStack;
    int left, right, swapIndex, tmpRight;
    pair<int, int> temp;
    sortStack.push(pair<int, int>(0, nums.size() - 1));
    while (!sortStack.empty()) {
        auto temp = sortStack.top();
        sortStack.pop();
        swapIndex = temp.first;
        left = swapIndex;
        right = temp.second;
        tmpRight = right;
        if (swapIndex >= right) continue;

        for (int i = left; i <= right; ++i) {
            if (nums[i] <= nums[swapIndex]) {
                swap(nums[i], nums[swapIndex]);
                swapIndex = i;
            } else {
                if (tmpRight <= swapIndex) break;
                swap(nums[tmpRight--], nums[i]);
                --i;
            }
        }
        sortStack.push(pair<int, int>(left, swapIndex - 1));
        sortStack.push(pair<int, int>(swapIndex + 1, right));
    }
}

void mergeSort(vector<int> &nums) {
    // 归并排序是一种分治思想的排序
    // 把数组拆分后排序，再将两个子数组合并
    // 一般是从上而下的递归，但是所有递归算法可以使用迭代写出来，如果是迭代的话，就是从下而上
    // 与堆排序类似，采用了类似于树的调用链，时间复杂度为O(nlogn)
    // 同时在排序时需要借助与原数组同样长度的辅助数组，因此空间复杂度为O(n)
    int firstIdx, secondIdx, mergeIdx;
    // 遍历递归分组长度，每次变为原长的两倍
    for (int i = 1; i < nums.size(); i *= 2) {
        // 按照当前间隔，两两一组，遍历子数组进行排序
        vector<int> mergeArray(nums.size());
        for (int j = 0; j < nums.size(); j += 2 * i) {
            mergeIdx = j;
            firstIdx = j;
            secondIdx = j + i;
            // 将排序好的数据填充到mergeArray中
            for (int k = j; k < min<int>(j + 2 * i, mergeArray.size()); ++k) {
                if (firstIdx >= j + i)
                    mergeArray[k] = nums[secondIdx++];
                else if (secondIdx >= j + i + i || secondIdx >= nums.size())
                    mergeArray[k] = nums[firstIdx++];
                else if (nums[firstIdx] < nums[secondIdx])
                    mergeArray[k] = nums[firstIdx++];
                else
                    mergeArray[k] = nums[secondIdx++];
            }
        }
        nums = mergeArray;
    }
}

void countSort(vector<int> &nums) {
    // 计数排序的思想是如果有n个小于k的数，那k的位置应该就是n
    // 在寻找n的时候，计数排序并没有基于比较，而是在一个额外空间中计数
    // 计数排序的时间复杂度时O(n+m),其中n是数组长度，m是数组的最大值最小值的差，
    // 也是额外空间的长度，也就是计数排序的空间复杂度是O(m)
    // 所以m的大小是影响计数排序性能的关键因素

    // 求最大最小
    // 时间复杂度O(n)
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int num : nums) {
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }

    // 时间复杂度O(n)
    vector<int> count(maxVal - minVal + 1, 0);
    for (int num : nums) {
        count[num - minVal]++;
    }

    // 时间复杂度O(m)
    int idx = 0;
    for (int i = 0; i < count.size(); ++i) {
        for (int j = 0; j < count[i]; ++j) {
            nums[idx++] = minVal + i;
        }
    }
}

void bucketSort(vector<int> &nums) {
    // 桶排序工作的原理是将数组分到有限数量的桶里
    // 每个桶再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）
    // 最后依次把各个桶中的记录列出来形成有序序列
    // 桶排序是计数排序的扩展版本，计数排序可以看成每个桶只存储相同元素，而桶排序每个桶存储一定范围的元素
    // 通过映射函数，将待排序数组中的元素映射到各个对应的桶中，对每个桶中的元素进行排序，最后将非空桶中的元素逐个放入原序列中
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
    }
    vector<vector<int>> buckets((maxVal - minVal + 9) / 10 + 1, vector<int>(0));
    for (int num : nums) {
        buckets[(num - minVal) / 10].push_back(num);
    }
    int idx = 0;
    for (vector<int> bucket : buckets) {
        quickSort(bucket);
        for (int num : bucket) {
            nums[idx++] = num;
        }
    }
}

void radixSort(vector<int> &nums) {
    // 好抽象的算法，完全不理解啥意思
    int exp = 0, idx;
    vector<vector<int>> buckets(10, vector<int>(0));
    while (true) {
        for (int num : nums) {
            buckets[static_cast<int>(num / pow(10, exp)) % 10].push_back(num);
        }
        if (buckets[0].size() == nums.size()) break;
        ++exp;
        idx = 0;
        for (vector<int> &bucket : buckets) {
            for (int num : bucket) {
                nums[idx++] = num;
            }
            bucket.clear();
        }
    }
}

void test(std::function<void(vector<int> &)> sortFunc) {
    int n = 100;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
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