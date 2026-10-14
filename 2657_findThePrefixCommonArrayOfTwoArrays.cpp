#include <iostream>
#include <vector>
using namespace std;

class Solution2657 {
public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		int n = A.size();
		vector<int> ans(n);
		// 统计每个数在两个数组中一共出现了几次（下标 0..i 范围内）
		vector<int> cnt(n + 1, 0);
		int common = 0;
		for (int i = 0;i < n;i++) {
			// 出现次数达到 2 次说明该数在两个前缀中都出现过
			if (++cnt[A[i]] == 2) common++;
			if (++cnt[B[i]] == 2) common++;
			ans[i] = common;
		}
		return ans;
	}
};

//int main() {
//	vector<int> A = {1, 3, 2, 4};
//	vector<int> B = {3, 1, 2, 4};
//	Solution2657 sol;
//	vector<int> res = sol.findThePrefixCommonArray(A, B);
//	for (int x : res) cout << x << " ";
//	cout << endl;
//	return 0;
//}
