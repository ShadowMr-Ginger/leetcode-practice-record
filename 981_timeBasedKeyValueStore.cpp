#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution981 {
public:
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) {
            return "";
        }

        const auto& history = it->second;
        int left = 0;
        int right = (int)history.size() - 1;
        int ans = -1;
        // 二分找最后一个不超过 timestamp 的时间点
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (history[mid].first <= timestamp) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (ans == -1) {
            return "";
        }
        return history[ans].second;
    }

private:
    // key 对应的时间序列，题目保证同一 key 时间递增
    unordered_map<string, vector<pair<int, string>>> store;
};

//int main() {
//	Solution981 obj;
//	obj.set("foo", "bar", 1);
//	cout << obj.get("foo", 1) << endl;
//	cout << obj.get("foo", 3) << endl;
//	obj.set("foo", "bar2", 4);
//	cout << obj.get("foo", 4) << endl;
//	cout << obj.get("foo", 5) << endl;
//	return 0;
//}
