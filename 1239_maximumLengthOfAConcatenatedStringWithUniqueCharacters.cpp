#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1239 {
private:
    int ans = 0;
    vector<int> masks;
    vector<int> lens;

    void dfs(int idx, int used, int cur_len) {
        ans = max(ans, cur_len); // 每个组合都可能成为答案
        for (int i = idx;i < (int)masks.size();i++) {
            if ((used & masks[i]) != 0) continue; // 与已选字符冲突，跳过
            dfs(i + 1, used | masks[i], cur_len + lens[i]);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        masks.clear();
        lens.clear();
        ans = 0;
        for (int i = 0;i < (int)arr.size();i++) { // 1. 过滤自身含重复的串并转位掩码
            int mask = 0;
            bool ok = true;
            for (char c : arr[i]) {
                int bit = 1 << (c - 'a');
                if ((mask & bit) != 0) {
                    ok = false;
                    break;
                }
                mask |= bit;
            }
            if (ok) {
                masks.push_back(mask);
                lens.push_back((int)arr[i].size());
            }
        }
        dfs(0, 0, 0); // 2. 枚举所有合法拼接
        return ans;
    }
};
//int main() {
//	Solution1239 sol;
//	vector<string> arr1 = {"un","iq","ue"};
//	cout << sol.maxLength(arr1) << endl;
//	vector<string> arr2 = {"cha","r","act","ers"};
//	cout << sol.maxLength(arr2) << endl;
//	vector<string> arr3 = {"abcdefghijklmnopqrstuvwxyz"};
//	cout << sol.maxLength(arr3) << endl;
//	return 0;
//}
