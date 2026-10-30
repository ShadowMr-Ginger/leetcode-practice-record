#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution2606 {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // 1. 建字母到权值的映射，默认 a~z 为 1~26
        int value[26];
        for (int i = 0;i < 26;i++) value[i] = i + 1;
        for (int i = 0;i < (int)chars.size();i++) {
            value[chars[i] - 'a'] = vals[i];
        }
        // 2. Kadane 求最大子数组和，空子串代价为 0，所以负了就重置
        int max_cost = 0;
        int cur = 0;
        for (char c : s) {
            cur += value[c - 'a'];
            if (cur < 0) cur = 0;
            max_cost = max(max_cost, cur);
        }
        return max_cost;
    }
};

//int main() {
//	Solution2606 sol;
//	string s = "adaa";
//	string chars = "d";
//	vector<int> vals = {-1000};
//	cout << sol.maximumCostSubstring(s, chars, vals) << endl;
//	string s2 = "abc";
//	string chars2 = "abc";
//	vector<int> vals2 = {-1, -1, -1};
//	cout << sol.maximumCostSubstring(s2, chars2, vals2) << endl;
//	return 0;
//}
