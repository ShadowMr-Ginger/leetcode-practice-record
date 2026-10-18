#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution3977 {
public:
    int minimumTime(int n, vector<vector<int>>& edges, int power) {
        // 1. 建图：edges[i] = {u, v, time, power_cost}
        vector<vector<tuple<int, int, int>>> graph(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], time = edge[2], cost = edge[3];
            graph[u].push_back({v, time, cost});
            graph[v].push_back({u, time, cost});
        }

        const int INF = INT_MAX / 2;
        // 2. dist[node][remain_power] 表示到达 node 且剩余 power 的最短时间
        vector<vector<int>> dist(n + 1, vector<int>(power + 1, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        dist[1][power] = 0;
        pq.push({0, 1, power});

        while (!pq.empty()) {
            auto [cur_time, node, remain] = pq.top();
            pq.pop();

            if (cur_time != dist[node][remain]) continue;
            if (node == n) return cur_time;

            for (auto [next, time, cost] : graph[node]) {
                if (remain < cost) continue;
                int next_remain = remain - cost;
                if (dist[next][next_remain] > cur_time + time) {
                    dist[next][next_remain] = cur_time + time;
                    pq.push({dist[next][next_remain], next, next_remain});
                }
            }
        }

        return -1;
    }
};

//int main() {
//	Solution3977 solution;
//	int n = 3;
//	vector<vector<int>> edges = {{1, 2, 2, 1}, {2, 3, 2, 1}, {1, 3, 5, 3}};
//	int power = 2;
//	cout << solution.minimumTime(n, edges, power) << endl;
//	return 0;
//}
