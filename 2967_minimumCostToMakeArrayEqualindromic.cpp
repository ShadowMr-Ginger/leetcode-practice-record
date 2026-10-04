#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution2967 {
public:
    long long minCost(vector<int>& nums) {
        // 1. 排序取中位数，使所有数相等的最优目标必在中位数附近
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        // 2. 候选回文数：取中位数的高位前缀，分别减一、不变、加一后镜像
        string s = to_string(median);
        int len = s.size();
        int half = stoi(s.substr(0, (len + 1) / 2));
        long long ans = LLONG_MAX;
        for (int d = -1;d <= 1;d++) {
            int h = half + d;
            if (h <= 0) continue;
            for (int odd = 0;odd <= 1;odd++) {
                long long p = make_pal(h, odd);
                ans = min(ans, calc(nums, p));
            }
        }
        // 3. 边界回文数：99...9 和 100...001
        if (len > 1) ans = min(ans, calc(nums, stoll(string(len - 1, '9'))));
        ans = min(ans, calc(nums, stoll("1" + string(len - 1, '0') + "1")));
        return ans;
    }

private:
    // 用前缀 h 镜像构造回文数，odd 表示总位数为奇数
    long long make_pal(int h, bool odd) {
        string s = to_string(h);
        string t = s;
        if (odd) t.pop_back();
        reverse(t.begin(), t.end());
        return stoll(s + t);
    }

    // 所有数变成 p 的总代价
    long long calc(vector<int>& nums, long long p) {
        long long cost = 0;
        for (int x : nums) {
            long long diff = (long long)x - p;
            cost += diff >= 0 ? diff : -diff;
        }
        return cost;
    }
};

//int main() {
//	vector<int> nums = {1,2,3,4,5};
//	Solution2967 sol;
//	cout << sol.minCost(nums) << endl;  // 6
//	return 0;
//}
