#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


// 搜索全图，一旦返现岛屿，用DFS沉没整座岛屿，时间复杂度O(n*m)，空间复杂度O(n*m)
class Solution200 {

private:
    // 预定义 方向向量
    int n, m;
    int directions[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x<0 || x >n - 1 || y<0 || y>m - 1 || grid[x][y] == '0') {
            return;
        }
        // 沉没
        grid[x][y] = '0';

        for (int i = 0;i < 4;i++) {
            dfs(grid, x + directions[i][0], y + directions[i][1]);
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {
        // 记录grid维度
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();
        if (m == 0) {
            return 0;
        }

        int n_island = 0;
        // 遍历全图
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                // 发现新岛屿
                if (grid[i][j] == '1') {
                    n_island++;
                    // 立刻把整座岛屿沉没
                    dfs(grid, i, j);
                }
            }
        }

        return n_island;
    }
};


//int main() {
//	Solution200 solution;
//	vector<vector<char>> grid = {
//		{'1','1','0','0','0'},
//		{'1','1','0','0','0'},
//		{'0','0','1','0','0'},
//		{'0','0','0','1','1'}
//	};
//	int result = solution.numIslands(grid);
//	cout << "Number of islands: " << result << endl; // Output: 3
//	return 0;
//}