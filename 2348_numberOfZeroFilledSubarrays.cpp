#include <iostream>
#include <vector>
using namespace std;

class Solution2348 {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int run = 0;
        // 遍历数组，统计当前连续 0 的长度
        for (int x : nums) {
            if (x == 0) {
                run++;
                // 以当前 0 结尾的全 0 子数组新增 run 个
                ans += run;
            } else {
                run = 0;
            }
        }
        return ans;
    }
};

//int main() {
//	Solution2348 solution;
//	vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
//	cout << solution.zeroFilledSubarray(nums) << endl;
//	return 0;
//}
