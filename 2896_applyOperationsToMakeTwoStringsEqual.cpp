#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution2896 {
public:
    long long minOperations(string s1, string s2) {
        int n = s1.size();
        vector<int> diff;
        // 1. 收集对应位不同的下标
        for (int i = 0;i < n;i++) {
            if (s1[i] != s2[i]) diff.push_back(i);
        }
        int m = diff.size();
        if (m % 2 == 1) return -1;
        long long ans = 0;
        // 2. 不同位数量必须为偶数，按顺序相邻配对代价最小
        for (int i = 0;i < m;i += 2) {
            ans += diff[i + 1] - diff[i];
        }
        return ans;
    }
//int main() {
//	Solution2896 sol;
//	string s1 = "1010";
//	string s2 = "0101";
//	cout << sol.minOperations(s1, s2) << endl; // 2
//	string s3 = "111";
//	string s4 = "000";
//	cout << sol.minOperations(s3, s4) << endl; // -1
//	return 0;
//}
};
