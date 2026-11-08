#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution456 {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) {
			return false;
		}
		stack<int> stk; // 候选的 "3"，单调递减栈
		int second = INT_MIN; // 当前最优的 "2"
		// 从右往左扫描，维护一个比当前元素小的最大 "2"
		for (int i = n - 1;i >= 0;i--) {
			// 1. nums[i] 比某个已确认的 "2" 还小，说明找到了 132
			if (nums[i] < second) {
				return true;
			}
			// 2. 弹出不满足单调性的元素，更新最大的 "2"
			while (!stk.empty() && nums[i] > stk.top()) {
				second = stk.top();
				stk.pop();
			}
			stk.push(nums[i]);
		}
		return false;
	}
};

//int main() {
//	Solution456 sol;
//	vector<int> nums1 = {1, 2, 3, 4};
//	cout << sol.find132pattern(nums1) << endl; // 0
//	vector<int> nums2 = {3, 1, 4, 2};
//	cout << sol.find132pattern(nums2) << endl; // 1
//	vector<int> nums3 = {-1, 3, 2, 0};
//	cout << sol.find132pattern(nums3) << endl; // 1
//	return 0;
//}
