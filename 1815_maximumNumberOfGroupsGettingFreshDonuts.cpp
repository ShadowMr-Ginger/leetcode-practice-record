#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1815 {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        // 统计各余数的出现次数
        vector<int> cnt(batchSize, 0);
        for (int g : groups) cnt[g % batchSize]++;
        // 余数为 0 的组一定开心，且不影响余数，直接计入答案
        int ans = cnt[0];
        cnt[0] = 0;
        // 将各余数剩余次数编码为 31 进制数（组数 n <= 30）
        long long start = 0;
        for (int i = batchSize - 1;i >= 0;i--) start = start * 31 + cnt[i];
        return ans + dfs(start, batchSize, 0);
    }
private:
    unordered_map<long long, int> memo;
    // 记忆化搜索：state 为各余数剩余次数的编码，cur 为当前余数
    int dfs(long long state, int batchSize, int cur) {
        if (state == 0) return 0;
        long long key = state * 10 + cur;
        if (memo.count(key)) return memo[key];
        int best = 0;
        long long tmp = state, base = 1;
        for (int i = 0;i < batchSize;i++) {
            int c = tmp % 31;
            tmp /= 31;
            if (c > 0) {
                // 安排一个余数为 i 的组，当前余数为 0 则该组开心
                long long ns = state - base;
                int happy = (cur == 0 ? 1 : 0);
                best = max(best, happy + dfs(ns, batchSize, (cur + i) % batchSize));
            }
            base *= 31;
        }
        memo[key] = best;
        return best;
    }
};

//int main() {
//	Solution1815 s;
//	vector<int> groups1 = {1,2,3,4,5,6};
//	vector<int> groups2 = {1,3,2,5,2,2,1,6};
//	cout << s.maxHappyGroups(3, groups1) << endl;
//	cout << s.maxHappyGroups(4, groups2) << endl;
//	return 0;
//}
