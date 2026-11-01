#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution608 {
public:
    vector<pair<int, string>> treeNode(vector<vector<int>>& rows) {
        unordered_set<int> parent_ids;
        // 1. 收集所有作为父节点出现的 id，-1 表示空父节点
        for (int i = 0;i < (int)rows.size();i++) {
            if (rows[i][1] != -1) {
                parent_ids.insert(rows[i][1]);
            }
        }

        vector<pair<int, string>> ans;
        // 2. 按根 / 叶子 / 内部节点分类
        for (int i = 0;i < (int)rows.size();i++) {
            if (rows[i][1] == -1) {
                ans.push_back({rows[i][0], "Root"});
            } else if (parent_ids.count(rows[i][0]) == 0) {
                ans.push_back({rows[i][0], "Leaf"});
            } else {
                ans.push_back({rows[i][0], "Inner"});
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

//int main() {
//	Solution608 s;
//	vector<vector<int>> rows = {{1, -1}, {2, 1}, {3, 1}, {4, 2}, {5, 2}};
//	auto res = s.treeNode(rows);
//	for (int i = 0;i < (int)res.size();i++) {
//		cout << res[i].first << " " << res[i].second << endl;
//	}
//	return 0;
//}
