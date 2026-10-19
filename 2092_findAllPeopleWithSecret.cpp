#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution2092 {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // 1. 按会议时间升序排序，同一时刻的秘密可在该组内互相传播
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        vector<bool> known(n, false);
        known[0] = true;
        known[firstPerson] = true;
        int m = meetings.size();
        vector<int> result;
        int i = 0;
        while (i < m) {
            int j = i;
            // 2. 取出时间相同的整组会议区间 [i, j)
            while (j < m && meetings[j][2] == meetings[i][2]) j++;
            unordered_map<int, int> parent;
            vector<int> people;
            function<int(int)> find = [&](int x) {
                if (!parent.count(x)) parent[x] = x;
                if (parent[x] != x) parent[x] = find(parent[x]);
                return parent[x];
            };
            // 3. 组内先合并所有会议边，并记录参与者
            for (int k = i;k < j;k++) {
                int x = meetings[k][0], y = meetings[k][1];
                parent[find(x)] = find(y);
                people.push_back(x);
                people.push_back(y);
            }
            // 4. 先找出与已知者连通的根，再统一标记，避免链式传播遗漏
            unordered_set<int> known_roots;
            for (int p : people) {
                if (known[p]) known_roots.insert(find(p));
            }
            for (int p : people) {
                if (known_roots.count(find(p))) known[p] = true;
            }
            i = j;
        }
        // 5. 收集所有最终知道秘密的人
        for (int p = 0;p < n;p++) {
            if (known[p]) result.push_back(p);
        }
        return result;
    }
};

//int main() {
//	Solution2092 s;
//	vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
//	vector<int> ans = s.findAllPeople(6, meetings, 1);
//	for (int p : ans) cout << p << " ";
//	cout << endl;
//	return 0;
//}
