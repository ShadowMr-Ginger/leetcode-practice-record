#include <iostream>
#include <vector>

using namespace std;

class Solution1920 {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        // 结果第 i 位就是 nums[nums[i]]
        for (int i = 0;i < n;i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

//int main() {
//	Solution1920 sol;
//	vector<int> nums = {0,2,1,5,3,4};
//	vector<int> ans = sol.buildArray(nums);
//	for (int i = 0;i < (int)ans.size();i++) {
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}
