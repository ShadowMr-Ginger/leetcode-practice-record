#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution3613 {
public:
    int minimizeMaxComponentCost(int n, vector<vector<int>>& edges, int k) {
        if (k == n) {
            return 0;
        }

        // 1. 按边权从小到大排序，等价于从小到大试探最大边权
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // 2. 初始化并查集，不断合并直到剩余 k 个连通块
        parent.resize(n);
        for (int i = 0;i < n;i++) {
            parent[i] = i;
        }

        int components = n;
        for (int i = 0;i < (int)edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (unite(u, v)) {
                components--;
                if (components == k) {
                    return w;
                }
            }
        }

        // 3. 边用完仍多于 k 个连通块，说明原图本身就不足 k 个
        return -1;
    }

private:
    vector<int> parent;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return false;
        }
        parent[px] = py;
        return true;
    }
};

//int main() {
//	Solution3613 sol;
//	int n = 5;
//	vector<vector<int>> edges = {{0, 1, 4}, {1, 2, 3}, {2, 3, 2}, {3, 4, 1}, {0, 4, 5}};
//	int k = 2;
//	cout << sol.minimizeMaxComponentCost(n, edges, k) << endl;
//	return 0;
//}
