#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

class Solution1857 {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        // 1. 建图并统计入度
        for (int i = 0;i < (int)edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        // 2. dp[u][c] 表示以 u 结尾的路径中颜色 c 的最大次数
        vector<array<int, 26>> dp(n);
        for (int i = 0;i < n;i++) {
            dp[i].fill(0);
            dp[i][colors[i] - 'a'] = 1;
        }

        queue<int> q;
        for (int i = 0;i < n;i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        int processed = 0;

        // 3. 拓扑排序同时转移，processed 不足 n 说明有环
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;

            for (int c = 0;c < 26;c++) {
                ans = max(ans, dp[u][c]);
            }

            for (int v : adj[u]) {
                for (int c = 0;c < 26;c++) {
                    dp[v][c] = max(dp[v][c], dp[u][c] + (colors[v] - 'a' == c ? 1 : 0));
                }
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (processed != n) {
            return -1;
        }
        return ans;
    }
};

//int main() {
//	Solution1857 sol;
//	string colors1 = "abaca";
//	vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{3,4}};
//	cout << sol.largestPathValue(colors1, edges1) << endl;
//
//	string colors2 = "a";
//	vector<vector<int>> edges2 = {{0,0}};
//	cout << sol.largestPathValue(colors2, edges2) << endl;
//	return 0;
//}
