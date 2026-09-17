/*

给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。



示例 1：

输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
示例 2：

输入：triangle = [[-10]]
输出：-10


提示：

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104


进阶：

你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <stack>
#include <array>
#include <numeric>
#include <queue>
using namespace std;



// 原做法：自顶向下的动态规划，空间复杂度 O(n)，时间复杂度 O(n^2)
class Solution120 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        int last_i_th_dp;
        dp[0] = triangle[0][0];
        for (int i = 1;i < n;i++) {
            for (int j = 0;j <= i;j++) {
                if (j == 0) {
                    last_i_th_dp = dp[j];
                    dp[0] = dp[0] + triangle[i][0];
                }
                else if (j == i) {
                    dp[j] = last_i_th_dp + triangle[i][j];
                }
                else {
                    int last_i_th_dp_replace = dp[j];
                    dp[j] = min(last_i_th_dp, last_i_th_dp_replace) + triangle[i][j];
                    last_i_th_dp = last_i_th_dp_replace;
                }
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};



// AI优化做法：自底向上的动态规划，空间复杂度 O(n)，时间复杂度 O(n^2)，但不需要处理边界问题，代码更简洁
class Solution130_PLUS {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // 初始化 dp 为三角形的最后一行，这是自底向上解法的精髓
        vector<int> dp(triangle.back());

        // 从倒数第二行开始，自底向上遍历
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // 状态转移方程：当前值 + 下方两个相邻位置中的较小值
                // 这个方程天然处理了边界，因为 dp[j] 和 dp[j+1] 始终有效
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

//int main() {
//	Solution120 solution;
//	vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
//	int result = solution.minimumTotal(triangle);
//	cout << "Minimum path sum: " << result << endl; // Output: 11
//	return 0;
//}