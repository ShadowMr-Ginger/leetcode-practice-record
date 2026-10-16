#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution1353 {
public:
    int maxEvents(vector<vector<int>>& events) {
        // 1. 按开始时间升序排序
        sort(events.begin(), events.end());
        int n = events.size();
        // 找到最晚的结束日，扫描范围不必超过它
        int max_day = 0;
        for (int i = 0;i < n;i++) max_day = max(max_day, events[i][1]);
        // 小顶堆存放当前可参加事件的结束时间
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int idx = 0;
        int cnt = 0;
        // 2. 逐天扫描，贪心选择
        for (int d = 1;d <= max_day;d++) {
            // 把今天开始的事件加入堆
            while (idx < n && events[idx][0] == d) min_heap.push(events[idx++][1]);
            // 丢掉已经在今天之前结束的事件
            while (!min_heap.empty() && min_heap.top() < d) min_heap.pop();
            // 3. 每天参加一个，优先选结束时间最早的
            if (!min_heap.empty()) {
                min_heap.pop();
                cnt++;
            }
        }
        return cnt;
    }
};

//int main() {
//	Solution1353 so;
//	vector<vector<int>> events = {{1,2},{2,3},{3,4},{1,2}};
//	cout << so.maxEvents(events) << endl;
//	vector<vector<int>> events2 = {{1,2},{1,2},{3,3},{1,5},{1,5}};
//	cout << so.maxEvents(events2) << endl;
//	return 0;
//}
