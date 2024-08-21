#include <gtest/gtest.h>

#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调递增的栈, <idx, countArea>
        // 元素入栈时，计算左侧的累积面积
        // 元素出栈时，计算右侧的累积面积
        // 具体看出栈入栈时的解析
        stack<pair<int, int>> singleStack;
        pair<int, int> info;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!(singleStack.empty() ||
                     heights[i] >= heights[singleStack.top().first])) {
                // 元素出栈，说明待入栈元素与当前元素之间的所有元素高度都比当前元素大，那右侧的每一列都可以成为当前元素的宽
                maxArea =
                    max(maxArea, singleStack.top().second +
                                     heights[singleStack.top().first] *
                                         (i - singleStack.top().first - 1));
                singleStack.pop();
            }
            // 元素入栈时如果栈为空，说明该元素之前的高度都比他大，那左侧的每一列都可以成为当前元素的宽
            if (singleStack.empty())
                singleStack.push(pair<int, int>(i, heights[i] * (i + 1)));
            // 如果元素入栈时不为空，说明栈顶元素与该元素之间的元素高度都比他大，那栈顶元素到该元素之间的每一列可以成为当前元素的宽
            else
                singleStack.push(pair<int, int>(
                    i, heights[i] * (i - singleStack.top().first)));
        }
        while (!singleStack.empty()) {
            // 与上面出栈时同理，区别在于当前没有待入栈元素，因此当前元素的右侧任意一列都可以作为他的宽
            // 如果当前右侧存在比他的大的元素，那么当前元素早就出栈了
            maxArea = max<int>(maxArea, singleStack.top().second +
                                            heights[singleStack.top().first] *
                                                (heights.size() - singleStack.top().first - 1));
            singleStack.pop();
        }
        return maxArea;
    }
};

void test(vector<int>& heights, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.largestRectangleArea(heights), ans);
}

TEST(Q84, CASE1) {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = 10;
    test(heights, ans);
}

TEST(Q84, CASE2) {
    vector<int> heights = {2, 1, 2};
    int ans = 3;
    test(heights, ans);
}

TEST(Q84, CASE3) {
    vector<int> heights = {4, 2, 0, 3, 2, 4, 3, 4};
    int ans = 10;
    test(heights, ans);
}