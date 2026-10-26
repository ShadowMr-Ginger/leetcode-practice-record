#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution2508 {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1, 0);
        unordered_set<long long> es;
        for (auto& e : edges) {
            int a = min(e[0], e[1]);
            int b = max(e[0], e[1]);
            deg[a]++;
            deg[b]++;
            es.insert((long long)a * (n + 1) + b);
        }

        vector<int> odd;
        for (int i = 1;i <= n;i++) {
            if (deg[i] % 2 == 1) odd.push_back(i);
        }

        int m = odd.size();
        if (m == 0) return true;
        if (m > 4) return false;

        if (m == 2) {
            int u = odd[0], v = odd[1];
            // 1. 两个奇点不相邻，直接连一条边
            if (!has_edge(es, u, v, n)) return true;
            // 2. 已相邻则找一个偶点中转，补两条边
            for (int x = 1;x <= n;x++) {
                if (x == u || x == v || deg[x] % 2 == 1) continue;
                if (!has_edge(es, u, x, n) && !has_edge(es, v, x, n)) return true;
            }
            return false;
        }

        // 4 个奇点枚举 3 种配对，两组都不能是旧边
        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
        if (!has_edge(es, a, b, n) && !has_edge(es, c, d, n)) return true;
        if (!has_edge(es, a, c, n) && !has_edge(es, b, d, n)) return true;
        if (!has_edge(es, a, d, n) && !has_edge(es, b, c, n)) return true;
        return false;
    }

private:
    bool has_edge(const unordered_set<long long>& es, int a, int b, int n) {
        if (a > b) swap(a, b);
        return es.find((long long)a * (n + 1) + b) != es.end();
    }
};

//int main() {
//	Solution2508 s;
//	vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,2},{1,4},{2,5}};
//	cout << s.isPossible(5, edges) << endl;
//	vector<vector<int>> edges2 = {{1,2},{3,4}};
//	cout << s.isPossible(4, edges2) << endl;
//	return 0;
//}
