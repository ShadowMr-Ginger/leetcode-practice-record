#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution2596 {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        // 1. 起点必须在左上角
        if (grid[0][0] != 0) {
            return false;
        }
        // 2. 记录每个序号所在的坐标
        vector<pair<int, int>> pos(n * n);
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
        // 3. 相邻序号的坐标差必须是马步 (1,2) 或 (2,1)
        for (int k = 0;k + 1 < n * n;k++) {
            int dx = abs(pos[k].first - pos[k + 1].first);
            int dy = abs(pos[k].second - pos[k + 1].second);
            if (dx * dy != 2) {
                return false;
            }
        }
        return true;
    }
};

//int main() {
//	Solution2596 s;
//	vector<vector<int>> grid1 = {{0, 11, 6, 9}, {5, 8, 1, 10}, {2, 13, 4, 7}, {15, 12, 3, 14}};
//	cout << s.checkValidGrid(grid1) << endl;	// 1
//	vector<vector<int>> grid2 = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
//	cout << s.checkValidGrid(grid2) << endl;	// 0
//	return 0;
//}
