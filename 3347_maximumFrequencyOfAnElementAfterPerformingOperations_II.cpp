#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution3347 {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<long long> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        long long kk = k;
        int ans = 1;
        // 1. 枚举最终保持不变的那个值（相同值连续成段）
        for (int i = 0;i < n;) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            int same = j - i;
            long long lo = a[i] - kk;
            long long hi = a[i] + kk;
            // 2. 若 [a[i]-k, a[i]+k] 内还有别的值，可把一个变成 a[i]
            int in_range = int(upper_bound(a.begin(), a.end(), hi) - lower_bound(a.begin(), a.end(), lo));
            int cand = same + (in_range - same > 0 ? 1 : 0);
            if (cand > ans) ans = cand;
            i = j;
        }
        return ans;
    }
};

//int main() {
//	vector<int> nums = {3, 9, 6};
//	Solution3347 sol;
//	cout << sol.maxFrequency(nums, 3) << endl; // 2
//	return 0;
//}
