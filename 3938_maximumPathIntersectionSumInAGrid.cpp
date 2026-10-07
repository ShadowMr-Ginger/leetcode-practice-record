#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution3938 {
public:
    int maximumPathIntersectionSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        // 两条路同步走，步数 k = r1 + c1 = r2 + c2，dp[r1][r2] 表示当前最大相交和
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0]; // 起点两路重合，只计一次
        for (int k = 1;k < 2 * n - 1;k++) {
            vector<vector<int>> ndp(n, vector<int>(n, INT_MIN));
            for (int r1 = 0;r1 < n;r1++) {
                int c1 = k - r1;
                if (c1 < 0 || c1 >= n) {
                    continue;
                }
                for (int r2 = 0;r2 < n;r2++) {
                    int c2 = k - r2;
                    if (c2 < 0 || c2 >= n) {
                        continue;
                    }
                    // 1. 枚举两条路上一步来源（只能来自上方或左方）
                    int best = INT_MIN;
                    for (int pr1 = r1 - 1;pr1 <= r1;pr1++) {
                        if (pr1 < 0) {
                            continue;
                        }
                        for (int pr2 = r2 - 1;pr2 <= r2;pr2++) {
                            if (pr2 < 0 || dp[pr1][pr2] == INT_MIN) {
                                continue;
                            }
                            best = max(best, dp[pr1][pr2]);
                        }
                    }
                    if (best == INT_MIN) {
                        continue;
                    }
                    // 2. 当前格重合才累加，且只计一次
                    int add = (r1 == r2) ? grid[r1][c1] : 0;
                    ndp[r1][r2] = best + add;
                }
            }
            dp = ndp;
        }
        return dp[n - 1][n - 1]; // 终点必重合，已在最后一次计入
    }
};

//int main() {
//	Solution3938 sol;
//	vector<vector<int>> grid = {{1, 2}, {3, 4}};
//	cout << sol.maximumPathIntersectionSum(grid) << endl; // 10
//	return 0;
//}
