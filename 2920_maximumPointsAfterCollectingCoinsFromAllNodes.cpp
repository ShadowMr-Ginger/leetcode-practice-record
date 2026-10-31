#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2920 {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins) {
        int n = coins.size();
        this->coins = coins;
        g.assign(n, {});
        for (const auto& e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dp.assign(n, vector<long long>(LOG, 0));
        sum.assign(n, vector<long long>(LOG, 0));
        dfs(0, -1);
        return (int)dp[0][0];
    }

private:
    static const int LOG = 15;
    vector<int> coins;
    vector<vector<int>> g;
    vector<vector<long long>> dp, sum;

    void dfs(int u, int p) {
        vector<long long> not_pick(LOG, 0), pick(LOG), total(LOG);
        for (int k = 0;k < LOG;k++) {
            total[k] = coins[u] >> k; // 祖先已减半 k 次后的子树金币和
            pick[k] = total[k];       // 选 u：当前子树金币全部计入
        }
        for (int v:g[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (int k = 0;k < LOG;k++) {
                not_pick[k] += dp[v][k];                  // 不选 u，子节点不再额外减半
                if (k + 1 < LOG) pick[k] += dp[v][k + 1]; // 选 u，子节点多被减半一次
                total[k] += sum[v][k];
            }
        }
        for (int k = 0;k < LOG;k++) dp[u][k] = max(not_pick[k], pick[k]);
        sum[u] = total;
    }

//int main() {
//	Solution2920 sol;
//	vector<vector<int>> edges1 = {{0,1},{1,2},{2,3}};
//	vector<int> coins1 = {10,10,10,10};
//	vector<vector<int>> edges2 = {{1,0},{0,2},{3,1},{1,4}};
//	vector<int> coins2 = {20,30,20,20,20};
//	cout << sol.maximumPoints(edges1, coins1) << endl;
//	cout << sol.maximumPoints(edges2, coins2) << endl;
//	return 0;
//}
};
