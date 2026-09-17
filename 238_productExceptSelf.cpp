#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 边界保护
        int n = nums.size();
        if (n <= 1) {
            return nums;
        }

        // 初始化answer表
        vector<int> answers(n);
        //  answer乘以前缀积
        answers[0] = 1;
        int prefix_product = 1;
        for (int i = 0;i < n;i++) {
            answers[i] = prefix_product;
            prefix_product *= nums[i];
        }

        // answer乘以后缀积
        int surfix_product = 1;
        for (int i = n - 1;i >= 0;i--) {
            answers[i] *= surfix_product;
            surfix_product *= nums[i];
        }

        return answers;
    }
};


//int main() {
//	vector<int> nums = { 1, 2, 3, 4 };
//	Solution238 sol;
//	vector<int> result = sol.productExceptSelf(nums);
//	cout << "Product except self: ";
//	for (int i = 0;i < result.size();i++) {
//		cout << result[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}