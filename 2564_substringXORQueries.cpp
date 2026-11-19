#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution2564 {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<int, int> first_pos;
        // 1. 预处理：以每个位置为起点累加二进制值，记录每个值最靠左的出现位置
        for (int i = 0;i < n;i++) {
            if (s[i] == '0') {
                // 值为 0 时最短子串就是单个 "0"，带前导零的不可能更短
                if (!first_pos.count(0)) first_pos[0] = i;
                continue;
            }
            int val = 0;
            // 查询值不超过 2^30，最多累加 30 位
            for (int j = i;j < min(n, i + 30);j++) {
                val = (val << 1) | (s[j] - '0');
                if (!first_pos.count(val)) first_pos[val] = i;
            }
        }
        // 2. 回答查询：目标值 = first ^ second
        vector<vector<int>> res;
        for (auto& q : queries) {
            int target = q[0] ^ q[1];
            if (first_pos.count(target)) {
                int l = first_pos[target];
                // 子串长度即二进制位数，0 特判为 1
                int len = (target == 0) ? 1 : 32 - __builtin_clz(target);
                res.push_back({l, l + len - 1});
            } else {
                res.push_back({-1, -1});
            }
        }
        return res;
    }
};

//int main() {
//	Solution2564 sol;
//	string s = "101101";
//	vector<vector<int>> queries = {{0,5},{1,2}};
//	vector<vector<int>> res = sol.substringXorQueries(s, queries);
//	for (auto& r : res) {
//		cout << r[0] << " " << r[1] << endl;
//	}
//	return 0;
//}
