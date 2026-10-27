#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1277 {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        // dp[i][j] 表示以 (i,j) 为右下角的全 1 正方形边长
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int total = 0;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // 受上方、左方、左上三个方向限制
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    total += dp[i][j];
                }
            }
        }
        return total;
    }

//int main() {
//	vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
//	Solution1277 sol;
//	cout << sol.countSquares(matrix) << endl;
//	return 0;
//}
};
