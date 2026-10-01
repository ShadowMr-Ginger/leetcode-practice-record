#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1615 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // 1. 建图：统计度数并记录两城市是否直接相连
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (auto& road : roads) {
            int a = road[0];
            int b = road[1];
            connected[a][b] = true;
            connected[b][a] = true;
            degree[a]++;
            degree[b]++;
        }
        // 2. 枚举所有城市对，若直接相连则网络秩减 1
        int max_rank = 0;
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                int rank = degree[i] + degree[j] - (connected[i][j] ? 1 : 0);
                max_rank = max(max_rank, rank);
            }
        }
        return max_rank;
    }
};

//int main() {
//	int n = 4;
//	vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
//	Solution1615 s;
//	cout << s.maximalNetworkRank(n, roads) << endl;
//	return 0;
//}
