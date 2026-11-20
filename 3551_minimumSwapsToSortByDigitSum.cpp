#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution3551 {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> order(n);
        for (int i = 0;i < n;i++) order[i] = i;
        // 按数位和升序，相同再按数值升序，得到目标下标顺序
        stable_sort(order.begin(), order.end(), [&](int a, int b) {
            int da = digit_sum(nums[a]);
            int db = digit_sum(nums[b]);
            if (da != db) return da < db;
            return nums[a] < nums[b];
        });
        // pos[i] 为原下标 i 排好后应在的位置
        vector<int> pos(n);
        for (int i = 0;i < n;i++) pos[order[i]] = i;
        vector<bool> vis(n, false);
        int cycles = 0;
        // 环数为 cycles 时，最少交换次数为 n - cycles
        for (int i = 0;i < n;i++) {
            if (vis[i]) continue;
            cycles++;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cur = pos[cur];
            }
        }
        return n - cycles;
    }

private:
    static int digit_sum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
};

//int main() {
//	Solution3551 sol;
//	vector<int> nums = { 37, 12, 25, 8 };
//	cout << sol.minSwaps(nums) << endl;
//	return 0;
//}
