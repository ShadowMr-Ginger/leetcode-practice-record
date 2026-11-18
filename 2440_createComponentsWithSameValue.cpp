#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution2440 {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int total = accumulate(nums.begin(), nums.end(), 0);

        // 1. 求出 total 的所有因子，从小到大尝试作为每块的和
        vector<int> divisors;
        for (int i = 1;(long long)i * i <= total;i++) {
            if (total % i == 0) {
                divisors.push_back(i);
                if (i != total / i) divisors.push_back(total / i);
            }
        }
        sort(divisors.begin(), divisors.end());

        // 2. 迭代 DFS 求遍历顺序和父亲，避免递归爆栈
        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<int> stk = {0};
        parent[0] = -2;
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            order.push_back(u);
            for (int v : g[u]) {
                if (parent[v] == -1) {
                    parent[v] = u;
                    stk.push_back(v);
                }
            }
        }

        // 3. 因子越小块数越多，找到第一个可行解即答案
        for (int target : divisors) {
            if (total / target > n) continue;
            if (canPartition(target, nums, parent, order)) {
                return total / target;
            }
        }
        return 1;
    }

private:
    // 判断能否把树切成若干块，每块节点值之和都是 target
    bool canPartition(int target, vector<int>& nums, vector<int>& parent, vector<int>& order) {
        int n = nums.size();
        vector<int> sum(nums.begin(), nums.end());
        // 逆序处理（先叶子后父亲）：和等于 target 就剪断，超过则失败
        for (int i = n - 1;i >= 0;i--) {
            int u = order[i];
            if (sum[u] > target) return false;
            if (sum[u] == target) continue;
            if (parent[u] >= 0) sum[parent[u]] += sum[u];
        }
        return true;
    }
};

//int main() {
//	Solution2440 sol;
//	vector<int> nums = {6,2,2,2,6};
//	vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
//	cout << sol.componentValue(nums, edges) << endl;
//	vector<int> nums2 = {2};
//	vector<vector<int>> edges2 = {};
//	cout << sol.componentValue(nums2, edges2) << endl;
//	return 0;
//}
