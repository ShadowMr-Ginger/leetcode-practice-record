#include <iostream>
#include <vector>
using namespace std;

class Solution2653 {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        // cnt[i] 记录值 (i - 50) 的出现次数，覆盖 [-50, 50]
        int cnt[101] = {0};
        vector<int> res;
        for (int i = 0;i < n;i++) {
            // 1. 右端元素进入窗口
            cnt[nums[i] + 50]++;
            // 2. 左端元素离开窗口
            if (i >= k) cnt[nums[i - k] + 50]--;
            if (i < k - 1) continue;
            // 3. 从最小负数开始累计频次，找第 x 小的负数
            int remain = x;
            int beauty = 0;
            for (int v = -50;v < 0;v++) {
                remain -= cnt[v + 50];
                if (remain <= 0) {
                    beauty = v;
                    break;
                }
            }
            // 4. 负数不足 x 个时保持 0
            res.push_back(beauty);
        }
        return res;
    }
};

//int main() {
//	Solution2653 solution;
//	vector<int> nums = {1, -1, -3, -2, 3};
//	int k = 3, x = 2;
//	vector<int> res = solution.getSubarrayBeauty(nums, k, x);
//	for (int v : res) cout << v << " ";
//	cout << endl;
//	return 0;
//}
