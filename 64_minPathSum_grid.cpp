/*

给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。



示例 1：


输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：

输入：grid = [[1,2,3],[4,5,6]]
输出：12


提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

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



// 原做法：自左上向右下的斜向下动态规划，空间复杂度 O(m)，时间复杂度 O(m*n).
class Solution64 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(min(m, n), 0);
        dp[0] = grid[0][0];
        // 斜向下，一斜列一斜列计算。
        for (int i = 1;i < m + n - 1;i++) {
            if (i < n) {
                int q = 0;
                int last_dp_q = dp[0];
                for (int p = i; p >= 0; p--) {
                    if (q == 0 || p == 0) {
                        dp[q] = last_dp_q + grid[q][p];
                    }
                    else {
                        int next_dp_q = dp[q];
                        dp[q] = min(last_dp_q, next_dp_q) + grid[q][p];
                        last_dp_q = next_dp_q;
                    }
                    q++;
                    if (q == m) {
                        break;
                    }
                }
            }
            else {
                int q = i - n + 1;
                int last_dp_q = dp[q - 1];
                for (int p = n - 1; p >= 0;p--) {
                    int next_dp_q = dp[q];
                    dp[q] = min(last_dp_q, next_dp_q) + grid[q][p];
                    last_dp_q = next_dp_q;
                    q++;
                    if (q == m) {
                        break;
                    }
                }
            }
        }

        return(dp[m - 1]);
    }
};

// AI给的优化做法：按行遍历，空间复杂度 O(n)，时间复杂度 O(m*n)，代码更简洁
class Solution64_PLUS {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 初始化 dp 为第一行的累加和
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // 从第二行开始，逐行更新
        for (int i = 1; i < m; ++i) {
            // 更新每行的第一个元素（只能从上方来）
            dp[0] += grid[i][0];
            // 更新该行其余元素
            for (int j = 1; j < n; ++j) {
                // 状态转移方程：当前值 + min(从左方来, 从上方来)
                // dp[j-1] 是当前行已更新的左方值，dp[j] 是上一行的上方值
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};

//
//int main() {
//	Solution64 solution;
//	vector<vector<int>> grid = { {1,3},{1,5},{4,2} };
//	int result = solution.minPathSum(grid);
//	cout << result << endl; // 输出 7
//	return 0;
//}