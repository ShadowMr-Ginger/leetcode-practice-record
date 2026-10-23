#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution3554 {
public:
    // 统计被至少 minUsers 个用户共同覆盖的类别对，按用户数降序、类别升序返回
    vector<vector<int>> findCategoryRecommendationPairs(vector<vector<int>>& userItems,
                                                        vector<int>& itemCategory,
                                                        int minUsers) {
        // 1. 建立 用户 -> 类别集合（去重）
        unordered_map<int, set<int>> userCats;
        for (auto& ui : userItems) {
            int user = ui[0];
            int item = ui[1];
            userCats[user].insert(itemCategory[item]);
        }

        // 2. 对每个用户内部做类别两两共现统计
        unordered_map<long long, int> pairCnt;
        for (auto& kv : userCats) {
            vector<int> cats(kv.second.begin(), kv.second.end());
            int m = cats.size();
            for (int i = 0;i < m;i++) {
                for (int j = i + 1;j < m;j++) {
                    long long key = (long long)cats[i] * 1000000 + cats[j];
                    pairCnt[key]++;
                }
            }
        }

        // 3. 过滤掉不满足阈值的对，再排序
        vector<vector<int>> res;
        for (auto& kv : pairCnt) {
            if (kv.second < minUsers) continue;
            int a = (int)(kv.first / 1000000);
            int b = (int)(kv.first % 1000000);
            res.push_back({a, b, kv.second});
        }
        sort(res.begin(), res.end(), [](vector<int>& x, vector<int>& y) {
            if (x[2] != y[2]) return x[2] > y[2];
            if (x[0] != y[0]) return x[0] < y[0];
            return x[1] < y[1];
        });
        return res;
    }

//int main() {
//	vector<vector<int>> userItems = {{1, 0}, {1, 1}, {2, 1}, {2, 2}, {3, 0}, {3, 2}};
//	vector<int> itemCategory = {0, 1, 2};
//	Solution3554 sol;
//	vector<vector<int>> ans = sol.findCategoryRecommendationPairs(userItems, itemCategory, 2);
//	for (auto& p : ans) {
//		cout << p[0] << " " << p[1] << " " << p[2] << "\n";
//	}
//	return 0;
//}
};
