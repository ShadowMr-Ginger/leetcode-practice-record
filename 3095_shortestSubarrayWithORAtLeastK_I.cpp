#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution3095 {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int left = 0; left < n; left++) {
            int cur_or = 0;
            for (int right = left; right < n; right++) {
                cur_or |= nums[right];
                // OR 单调不降，首次满足即 left 起最短
                if (cur_or >= k) {
                    if (right - left + 1 < ans) {
                        ans = right - left + 1;
                    }
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//int main() {
//	Solution3095 sol;
//	vector<int> nums = {1, 2, 3};
//	cout << sol.minimumSubarrayLength(nums, 2) << endl;
//	vector<int> nums2 = {2, 1, 8};
//	cout << sol.minimumSubarrayLength(nums2, 10) << endl;
//	return 0;
//}
