#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <functional>
using namespace std;

class Solution3342 {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        const long long INF = LLONG_MAX;

        // dist[(i*m+j)*2+k]：到达 (i,j) 且已走步数奇偶为 k 的最少时间
        vector<long long> dist(2 * n * m, INF);
        priority_queue<tuple<long long,int,int,int>, vector<tuple<long long,int,int,int>>, greater<>> pq;

        dist[0] = 0;
        pq.emplace(0, 0, 0, 0);

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        long long ans = INF;

        while (!pq.empty()) {
            auto [t, i, j, par] = pq.top();
            pq.pop();

            int id = (i * m + j) * 2 + par;
            if (t != dist[id]) continue;
            if (i == n - 1 && j == m - 1) ans = min(ans, t);
            if (t >= ans) continue;

            for (int k = 0;k < 4;k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                // 第 1、3、5... 次移动耗时 1，第 2、4... 次耗时 2
                int cost = (par == 0 ? 1 : 2);
                long long nt = max(t, (long long)moveTime[ni][nj]) + cost;
                int nid = (ni * m + nj) * 2 + (par ^ 1);

                if (nt < dist[nid]) {
                    dist[nid] = nt;
                    pq.emplace(nt, ni, nj, par ^ 1);
                }
            }
        }

        return (int)ans;
    }
};

//int main() {
//	Solution3342 sol;
//	vector<vector<int>> moveTime = {{0,4},{4,4}};
//	cout << sol.minTimeToReach(moveTime) << endl;
//	moveTime = {{0,0,0},{0,0,0}};
//	cout << sol.minTimeToReach(moveTime) << endl;
//	return 0;
//}
