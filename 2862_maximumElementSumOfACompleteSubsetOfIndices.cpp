#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution2862 {
public:
    long long maximumSum(vector<int>& nums) {
        // i*j 为完全平方数 当且仅当 i、j 的平方自由核相同，按核分组求最大组和
        unordered_map<int, long long> group_sum;
        long long result = 0;
        int n = nums.size();
        for (int i = 1;i <= n;i++) {
            int key = square_free(i);
            group_sum[key] += nums[i - 1];
            result = max(result, group_sum[key]);
        }
        return result;
    }

private:
    // 求 x 的平方自由核：每个质因子只保留指数的奇偶性
    int square_free(int x) {
        int kernel = 1;
        for (int p = 2;p * p <= x;p++) {
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt ^= 1;
            }
            if (cnt == 1) {
                kernel *= p;
            }
        }
        return kernel * x; // 剩余部分是指数为奇数的质因子
    }
};

//int main() {
//	Solution2862 s;
//	vector<int> nums1 = {8, 7, 3, 5, 7, 2, 2, 9, 8, 5, 8, 6};
//	cout << s.maximumSum(nums1) << endl;
//	vector<int> nums2 = {8, 10, 3, 8, 1, 13, 8, 5, 8, 2, 5, 3};
//	cout << s.maximumSum(nums2) << endl;
//	return 0;
//}
