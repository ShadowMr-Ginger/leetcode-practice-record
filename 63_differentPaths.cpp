/*
给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。

网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。

返回机器人能够到达右下角的不同路径数量。

测试用例保证答案小于等于 2 * 10^9。

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

// 原做法：基于曼哈顿距离的动态规划，空间复杂度 O(n*m)，时间复杂度 O(n*m)
class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        queue<vector<int>> q;
        q.push({ 0, 0 });
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> methods(m, vector<int>(n, 0));
        methods[0][0] = 1;
        while (!q.empty()) {
            int num_nodes = q.size();
            for (int i = 0; i < num_nodes; i++) {
                vector<int> p = q.front();
                q.pop();
                int crnt_methods = methods[p[0]][p[1]];
                // down
                if (p[0] + 1 != m && !obstacleGrid[p[0] + 1][p[1]]) {
                    if (methods[p[0] + 1][p[1]] == 0) {
                        q.push({ p[0] + 1, p[1] });
                    }
                    methods[p[0] + 1][p[1]] += crnt_methods;
                }
                // right
                if (p[1] + 1 != n && !obstacleGrid[p[0]][p[1] + 1]) {
                    if (methods[p[0]][p[1] + 1] == 0) {
                        q.push({ p[0], p[1] + 1 });
                    }
                    methods[p[0]][p[1] + 1] += crnt_methods;
                }
            }
        }

        return methods[m - 1][n - 1];
    }
};


// 优化做法：从上到下，空间复杂度 O(n)，时间复杂度 O(n*m)
/*
💡 核心原理解析
dp[j] 的双重身份：在处理第 i 行第 j 列时，dp[j] 尚未被更新，它保存的正是上一行（第 i-1 行）第 j 列的值，即从上方来的路径数。
dp[j-1] 的即时性：由于内层循环从左往右遍历，dp[j-1] 已经被更新为当前行（第 i 行）的值，即从左方来的路径数。
合并更新：dp[j] += dp[j-1] 一行代码就完成了“上方 + 左方”的状态转移。
障碍物处理：遇到障碍物直接 dp[j] = 0，既表示该位置不可达，也阻断了后续位置通过它获取路径数。
*/
class Solution63_PLUS {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 一维 dp 数组，dp[j] 表示到达当前行第 j 列的路径数
        vector<int> dp(n, 0);
        dp[0] = 1; // 起点

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    // 当前位置是障碍物，路径数为 0
                    dp[j] = 0;
                }
                else if (j > 0) {
                    // dp[j]（未更新前）= 从上方来的路径数
                    // dp[j-1]（已更新）= 从左方来的路径数
                    dp[j] += dp[j - 1];
                }
                // j == 0 且非障碍物时，dp[0] 保持不变（继承上方）
            }
        }

        return dp[n - 1];
    }
};


//int main() {
//	Solution63 solution;
//	vector<vector<int>> obstacleGrid = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
//	int result = solution.uniquePathsWithObstacles(obstacleGrid);
//	cout << result << endl; // 输出: 2
//	return 0;
//}