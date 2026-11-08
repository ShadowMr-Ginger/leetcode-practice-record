#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2151 {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int best = 0;
        // 1. 枚举所有人好坏状态（第 i 位为 1 表示第 i 个人是好人），n <= 15 可暴力
        for (int mask = 0;mask < (1 << n);mask++) {
            if (check(statements, mask, n)) {
                best = max(best, __builtin_popcount(mask));
            }
        }
        return best;
    }

private:
    // 校验该状态是否自洽：好人说的每句话都要与其余人的实际状态一致
    bool check(vector<vector<int>>& statements, int mask, int n) {
        for (int i = 0;i < n;i++) {
            if (!(mask & (1 << i))) {
                continue; // 坏人说话不必满足
            }
            for (int j = 0;j < n;j++) {
                if (statements[i][j] == 2) {
                    continue; // 未发言
                }
                int actual = (mask >> j) & 1;
                if (statements[i][j] != actual) {
                    return false;
                }
            }
        }
        return true;
    }
};

//int main() {
//	Solution2151 solution;
//	vector<vector<int>> statements = {{2,1,2},{1,2,2},{2,0,2}};
//	cout << solution.maximumGood(statements) << endl;
//	return 0;
//}
