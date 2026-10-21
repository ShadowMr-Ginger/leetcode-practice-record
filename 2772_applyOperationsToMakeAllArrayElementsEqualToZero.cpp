#include <iostream>
#include <vector>

using namespace std;

class Solution2772 {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        // 差分数组记录每个位置被累计减去的值
        vector<int> diff(n + 1, 0);
        int cur = 0; // 当前位置实际被减去的总量
        for (int i = 0;i < n;i++) {
            cur += diff[i];
            int remain = nums[i] - cur;
            if (remain < 0) return false; // 减过头无法恢复
            if (remain == 0) continue;
            if (i + k > n) return false; // 剩余长度不足 k，无法以 i 为起点
            // 1. 以 i 为起点执行 remain 次操作，把 nums[i] 归零
            cur += remain;
            diff[i + k] -= remain; // 操作只影响 [i, i+k-1]
        }
        return true;
    }
};

//int main() {
//	vector<int> nums = {2,2,3,1,1,0};
//	int k = 3;
//	Solution2772 solution;
//	cout << solution.checkArray(nums, k) << endl;
//	return 0;
//}
