#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution1091 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // 1. 从左上角开始广度优先搜索
        dist[0][0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }

            // 2. 尝试八个方向，第一次到达即为最短路径
            for (int i = 0;i < 8;i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == 1 || dist[nx][ny] != -1) {
                    continue;
                }

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        return -1;
    }
};

//int main() {
//	Solution1091 solution;
//	vector<vector<int>> grid = {{0, 1}, {1, 0}};
//	cout << solution.shortestPathBinaryMatrix(grid) << endl;
//	return 0;
//}
