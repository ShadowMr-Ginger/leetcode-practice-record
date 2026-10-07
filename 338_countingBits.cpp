#include <vector>

using namespace std;

class Solution338 {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1;i <= n;i++) {
            // 1. 当前数去掉最低位后，1 的个数加最低位本身
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

//int main() {
//	Solution338 s;
//	vector<int> res = s.countBits(5);
//	for (int num : res) {
//		cout << num << " ";
//	}
//	cout << endl;
//	return 0;
//}
