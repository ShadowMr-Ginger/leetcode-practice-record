#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution2035 {
public:
    int minimumDifference(vector<int>& nums) {
        int n = (int)nums.size();
        int m = n / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        // 1. 枚举左右两半的所有子集和，并按选取个数分组
        vector<vector<int>> left_sums = build(m, nums, 0);
        vector<vector<int>> right_sums = build(m, nums, m);

        int ans = INT_MAX;
        for (int k = 0;k <= m;k++) {
            int need = m - k;
            for (int s : left_sums[k]) {
                // 2. 另一半需要接近 total / 2 - s
                int target = total / 2 - s;
                auto it = lower_bound(right_sums[need].begin(), right_sums[need].end(), target);

                if (it != right_sums[need].end()) {
                    ans = min(ans, abs(total - 2 * (s + *it)));
                }
                if (it != right_sums[need].begin()) {
                    --it;
                    ans = min(ans, abs(total - 2 * (s + *it)));
                }
            }
        }
        return ans;
    }

private:
    vector<vector<int>> build(int m, const vector<int>& nums, int offset) {
        vector<vector<int>> sums(m + 1);
        int size = 1 << m;

        for (int mask = 0;mask < size;mask++) {
            int cnt = 0;
            int s = 0;
            for (int i = 0;i < m;i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    s += nums[offset + i];
                }
            }
            sums[cnt].push_back(s);
        }

        for (int k = 0;k <= m;k++) {
            sort(sums[k].begin(), sums[k].end());
        }
        return sums;
    }
};

//int main() {
//	Solution2035 solution;
//	vector<int> nums = {3,9,7,3};
//	cout << solution.minimumDifference(nums) << endl;
//	vector<int> nums2 = {-36,36};
//	cout << solution.minimumDifference(nums2) << endl;
//	vector<int> nums3 = {2,-1,0,4,-2,-9};
//	cout << solution.minimumDifference(nums3) << endl;
//	return 0;
//}
