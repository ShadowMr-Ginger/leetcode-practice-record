#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution3589 {
public:
    long long countPrimeGapBalancedSubarrays(vector<int>& nums) {
        if (nums.empty()) return 0;
        int limit = *max_element(nums.begin(), nums.end());
        // 筛出 [0, limit] 的质数
        vector<char> is_prime(limit + 1, true);
        if (limit >= 0) is_prime[0] = false;
        if (limit >= 1) is_prime[1] = false;
        for (int p = 2;(long long)p * p <= limit;p++) {
            if (is_prime[p]) {
                for (int j = p * p;j <= limit;j += p) is_prime[j] = false;
            }
        }

        // 质数记 +1，非质数记 -1，统计前缀和为 0 的子数组
        unordered_map<long long, int> cnt;
        cnt.reserve(nums.size() * 2);
        cnt[0] = 1;
        long long sum = 0;
        long long ans = 0;
        for (int x : nums) {
            sum += is_prime[x] ? 1 : -1;
            ans += cnt[sum];
            cnt[sum]++;
        }
        return ans;
    }
};

//int main() {
//	vector<int> nums = {1, 2, 3, 4};
//	Solution3589 sol;
//	cout << sol.countPrimeGapBalancedSubarrays(nums) << endl;
//	return 0;
//}
