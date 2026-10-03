#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution1547 {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size() + 2;
        vector<int> positions(m);
        positions[0] = 0;
        positions[m - 1] = n;
        for (int i = 0;i < (int)cuts.size();i++) positions[i + 1] = cuts[i];
        sort(positions.begin(), positions.end());

        // dp[i][j]：只切 positions[i] 与 positions[j] 之间的点所需的最小代价
        vector<vector<int>> dp(m, vector<int>(m, 0));
        // 1. 枚举区间长度
        for (int len = 2;len < m;len++) {
            for (int i = 0;i + len < m;i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                // 2. 枚举区间内第一个切点 k
                for (int k = i + 1;k < j;k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + positions[j] - positions[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
};

//int main() {
//	Solution1547 solution;
//	int n = 7;
//	vector<int> cuts = {1, 3, 4, 5};
//	cout << solution.minCost(n, cuts) << endl;
//	int n2 = 9;
//	vector<int> cuts2 = {5, 6, 1, 4, 2};
//	cout << solution.minCost(n2, cuts2) << endl;
//	return 0;
//}
