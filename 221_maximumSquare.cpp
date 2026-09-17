/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。



示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4
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


class Solution221 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0;i < m;i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for (int j = 0;j < n;j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                ans = 1;
            }
        }
        for (int i = 1;i < m;i++) {
            for (int j = 1;j < n;j++) {
                if (matrix[i][j] == '1') {
                    int tmp = min(dp[i - 1][j - 1], dp[i - 1][j]);
                    int min_sub_square = min(tmp, dp[i][j - 1]);
                    dp[i][j] = 1 + min_sub_square;
                    if (dp[i][j] > ans) {
                        ans = dp[i][j];
                    }
                }
            }
        }

        return ans * ans;
    }
};

//int main() {
//	Solution221 s;
//	vector<vector<char>> matrix = { {'1','0','1','0','0'},
//									 {'1','0','1','1','1'},
//									 {'1','1','1','1','1'},
//									 {'1','0','0','1','0'} };
//	cout << s.maximalSquare(matrix) << endl; // 输出 4
//	return 0;
//}