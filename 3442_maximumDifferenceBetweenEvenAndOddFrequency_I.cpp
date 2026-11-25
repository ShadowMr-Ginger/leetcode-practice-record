#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution3442 {
public:
    int maxDifference(string s) {
        // 统计每个字符的出现次数
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        // 找最大奇数频率和最小偶数频率
        int max_odd = INT_MIN, min_even = INT_MAX;
        for (auto& p : cnt) {
            if (p.second % 2 == 1) {
                max_odd = max(max_odd, p.second);
            } else {
                min_even = min(min_even, p.second);
            }
        }
        return max_odd - min_even;
    }
};

//int main() {
//	Solution3442 sol;
//	cout << sol.maxDifference("aaaaabbc") << endl;	// 输出 3
//	cout << sol.maxDifference("abcabcab") << endl;	// 输出 1
//	return 0;
//}
