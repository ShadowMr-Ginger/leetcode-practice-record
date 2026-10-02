#include <iostream>
#include <vector>
using namespace std;

class Solution463 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        int perimeter = 0;

        // 1. 遍历每个陆地格子，先假设四条边都在周长里
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    // 2. 与上方、左方相邻会共享一条边，每对相邻陆地少 2
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};

//int main() {
//	vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
//	Solution463 solution;
//	cout << solution.islandPerimeter(grid) << endl;
//	return 0;
//}
