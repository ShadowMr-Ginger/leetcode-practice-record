#include <vector>
using namespace std;

class Solution3906 {
public:
    long long countGoodIntegers(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[j][r] 表示处理到当前行第 j 列、余数为 r 的路径数
        vector<vector<long long>> prev(m, vector<long long>(k, 0));
        prev[0][((grid[0][0] % k) + k) % k] = 1;

        for (int i = 0;i < n;i++) {
            vector<vector<long long>> cur(m, vector<long long>(k, 0));
            for (int j = 0;j < m;j++) {
                int digit = ((grid[i][j] % k) + k) % k;
                for (int r = 0;r < k;r++) {
                    long long ways = 0;

                    // 1. 从上方转移
                    if (i > 0) {
                        ways += prev[j][r];
                    }
                    // 2. 从左方转移
                    if (j > 0) {
                        ways += cur[j - 1][r];
                    }

                    // 3. 拼接当前数字后更新余数
                    int nr = (r * 10 + digit) % k;
                    cur[j][nr] += ways;
                }
            }
            prev = cur;
        }

        // 好整数要求最终拼接出的数能被 k 整除
        return prev[m - 1][0];
    }
};

//int main() {
//	Solution3906 sol;
//	vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//	int k = 3;
//	cout << sol.countGoodIntegers(grid, k) << endl;
//	return 0;
//}
