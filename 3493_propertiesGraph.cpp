#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution3493 {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        // 每行转成集合，便于统计公共属性
        vector<unordered_set<int>> prop_sets(n);
        for (int i = 0;i < n;i++) {
            for (int x : properties[i]) {
                prop_sets[i].insert(x);
            }
        }
        init(n);
        // 枚举所有点对，公共属性数 >= k 就连一条边
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                int common = 0;
                for (int x : prop_sets[i]) {
                    if (prop_sets[j].count(x)) {
                        common++;
                    }
                }
                if (common >= k) {
                    unite(i, j);
                }
            }
        }
        // 统计不同根的数量，即连通分量个数
        int ans = 0;
        for (int i = 0;i < n;i++) {
            if (find(i) == i) {
                ans++;
            }
        }
        return ans;
    }

private:
    vector<int> parent;

    void init(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) {
            parent[ra] = rb;
        }
    }
};

//int main() {
//	Solution3493 solution;
//	vector<vector<int>> properties = {{1,2},{1,1},{3,4},{4,5},{5,6},{7,7}};
//	int k = 1;
//	cout << solution.numberOfComponents(properties, k) << endl; // 3
//	return 0;
//}
