#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution752 {
public:
    int openLock(vector<string>& deadends, string target) {
        // 1. 初始化死锁集合，起点被封则直接失败
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        queue<string> q;
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");
        int steps = 0;

        // 2. 按转动次数分层 BFS
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0;i < size;i++) {
                string cur = q.front();
                q.pop();

                // 3. 逐位尝试向上、向下拨动一格
                for (int j = 0;j < 4;j++) {
                    string nxt = cur;

                    nxt[j] = cur[j] == '9' ? '0' : char(cur[j] + 1);
                    if (!visited.count(nxt) && !dead.count(nxt)) {
                        if (nxt == target) return steps + 1;
                        visited.insert(nxt);
                        q.push(nxt);
                    }

                    nxt[j] = cur[j] == '0' ? '9' : char(cur[j] - 1);
                    if (!visited.count(nxt) && !dead.count(nxt)) {
                        if (nxt == target) return steps + 1;
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

//int main() {
//	Solution752 solution;
//	vector<string> deadends1 = {"0201", "0101", "0102", "1212", "2002"};
//	cout << solution.openLock(deadends1, "0202") << endl;
//	vector<string> deadends2 = {"8888"};
//	cout << solution.openLock(deadends2, "0009") << endl;
//	return 0;
//}
