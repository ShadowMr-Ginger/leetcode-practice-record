#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1895 {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        row_ps.assign(m, vector<int>(n + 1, 0));
        col_ps.assign(m + 1, vector<int>(n, 0));
        diag_ps.assign(m + 1, vector<int>(n + 1, 0));
        anti_ps.assign(m + 1, vector<int>(n + 2, 0));

        // 1. 预处理行、列、主对角线、副对角线前缀和
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                row_ps[i][j + 1] = row_ps[i][j] + grid[i][j];
                col_ps[i + 1][j] = col_ps[i][j] + grid[i][j];
                diag_ps[i + 1][j + 1] = diag_ps[i][j] + grid[i][j];
                anti_ps[i + 1][j + 1] = anti_ps[i][j + 2] + grid[i][j];
            }
        }

        // 2. 从大到小枚举边长，找到直接返回
        for (int k = min(m, n);k >= 2;k--) {
            for (int r = 0;r + k <= m;r++) {
                for (int c = 0;c + k <= n;c++) {
                    if (is_magic(r, c, k)) {
                        return k;
                    }
                }
            }
        }

        return 1;
    }

private:
    int m, n;
    vector<vector<int>> row_ps, col_ps, diag_ps, anti_ps;

    bool is_magic(int r, int c, int k) {
        // 以第一行作为目标和，逐行逐列校验
        int target = row_ps[r][c + k] - row_ps[r][c];

        for (int i = 0;i < k;i++) {
            if (row_ps[r + i][c + k] - row_ps[r + i][c] != target) {
                return false;
            }
        }
        for (int j = 0;j < k;j++) {
            if (col_ps[r + k][c + j] - col_ps[r][c + j] != target) {
                return false;
            }
        }

        int main_sum = diag_ps[r + k][c + k] - diag_ps[r][c];
        int anti_sum = anti_ps[r + k][c + 1] - anti_ps[r][c + k + 1];
        return main_sum == target && anti_sum == target;
    }
};

//int main() {
//	Solution1895 sol;
//	vector<vector<int>> grid = {
//		{7, 1, 4, 5, 6},
//		{2, 5, 1, 6, 4},
//		{1, 5, 4, 3, 2},
//		{1, 2, 7, 3, 4}
//	};
//	cout << sol.largestMagicSquare(grid) << endl;
//	return 0;
//}
