#include <iostream>
#include <vector>

using namespace std;

class Solution3158 {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0, xor_one = 0;
        // 1. 异或数组中所有元素
        for (int i = 0;i < n;i++) {
            xor_all ^= nums[i];
        }
        // 2. 异或 1 到 n（每个元素出现一次或两次，且值在 [1,n] 内）
        for (int i = 1;i <= n;i++) {
            xor_one ^= i;
        }
        // 出现一次的数抵消，出现两次的数保留在结果中
        return xor_all ^ xor_one;
    }
};

//int main() {
//	vector<int> nums = {1,2,1,3};
//	Solution3158 s;
//	cout << s.duplicateNumbersXOR(nums) << endl;
//	return 0;
//}
