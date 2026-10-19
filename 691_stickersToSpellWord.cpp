#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution691 {
public:
    int minStickers(vector<string>& stickers, string target) {
        this->target = target;
        m = target.size();
        target_cnt.assign(26, 0);
        for (char c : target) target_cnt[c - 'a']++;

        // 只保留含有目标字符的贴纸
        for (auto& s : stickers) {
            vector<int> cnt(26, 0);
            bool useful = false;
            for (char c : s) {
                if (target_cnt[c - 'a'] > 0) {
                    cnt[c - 'a']++;
                    useful = true;
                }
            }
            if (useful) sticker_cnt.push_back(cnt);
        }

        memo.assign(1 << m, -2);
        return dfs((1 << m) - 1);
    }

private:
    string target;
    int m;
    vector<int> target_cnt;
    vector<vector<int>> sticker_cnt;
    vector<int> memo;

    int dfs(int mask) {
        if (mask == 0) return 0;
        if (memo[mask] != -2) return memo[mask];

        // 取一个剩余字符，枚举能覆盖它的贴纸
        int i = __builtin_ctz(mask);
        char ch = target[i];
        int best = INT_MAX;
        for (auto& sc : sticker_cnt) {
            if (sc[ch - 'a'] == 0) continue;

            // 这张贴纸能覆盖的剩余字符尽量覆盖
            vector<int> cnt = sc;
            int nmask = mask;
            for (int j = 0;j < m;j++) {
                if ((nmask >> j) & 1 && cnt[target[j] - 'a'] > 0) {
                    cnt[target[j] - 'a']--;
                    nmask &= ~(1 << j);
                }
            }
            int sub = dfs(nmask);
            if (sub != -1) best = min(best, sub + 1);
        }

        memo[mask] = best == INT_MAX ? -1 : best;
        return memo[mask];
    }

//int main() {
//	Solution691 sol;
//	vector<string> stickers = {"with", "example", "science"};
//	string target = "thehat";
//	cout << sol.minStickers(stickers, target) << endl;
//	return 0;
//}
};
