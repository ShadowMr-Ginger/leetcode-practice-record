#include <vector>
using namespace std;

class Solution1018 {
public:
	vector<bool> prefixesDivBy5(vector<int>& nums) {
		vector<bool> res;
		int rem = 0;
		// 1. 逐位扩展前缀，维护当前数值对 5 的余数
		for (int i = 0;i < nums.size();i++) {
			// 2. 二进制末尾追加一位：rem = rem * 2 + bit，再取模防止溢出
			rem = (rem * 2 + nums[i]) % 5;
			res.push_back(rem == 0);
		}
		return res;
	}
};

//int main() {
//	Solution1018 solution;
//	vector<int> nums = {0,1,1};
//	vector<bool> res = solution.prefixesDivBy5(nums);
//	for (bool b : res) {
//		cout << (b ? "true" : "false") << " ";
//	}
//	return 0;
//}
