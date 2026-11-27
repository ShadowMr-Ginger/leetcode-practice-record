#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution3196 {
public:
	long long maximumTotalCost(vector<int>& nums) {
		int n = nums.size();
		// plus/minus：当前元素在当前子数组中取正/负号时的最大总代价
		long long plus = nums[0];
		long long minus = LLONG_MIN / 4;
		for (int i = 1;i < n;i++) {
			long long best = max(plus, minus);
			long long new_plus = best + nums[i];
			long long new_minus = plus - nums[i];
			plus = new_plus;
			minus = new_minus;
		}
		return max(plus, minus);
	}
};
//int main() {
//	Solution3196 solution;
//	vector<int> nums1 = {1, -2, 3, 4};
//	cout << solution.maximumTotalCost(nums1) << endl;
//	vector<int> nums2 = {0, 2, 1};
//	cout << solution.maximumTotalCost(nums2) << endl;
//	return 0;
//}
