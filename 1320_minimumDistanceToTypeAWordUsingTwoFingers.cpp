#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution1320 {
public:
	int minimumDistance(string word) {
		int n = word.size();
		// dp[p]：按完当前前缀后，一只手在最新字母上，另一只手在 p（26 表示空闲）的最小代价
		vector<int> cur(27, INT_MAX / 2), nxt(27, INT_MAX / 2);
		cur[26] = 0; // 1. 初始两指均未使用
		for (int i = 0;i < n;i++) {
			int a = i == 0 ? 26 : word[i - 1] - 'a'; // 2. 按过上一字母的手的位置
			int b = word[i] - 'a'; // 3. 当前要按的字母
			fill(nxt.begin(), nxt.end(), INT_MAX / 2);
			for (int p = 0;p <= 26;p++) {
				if (cur[p] >= INT_MAX / 2) continue;
				// 4. 继续用按过上一字母的手
				nxt[p] = min(nxt[p], cur[p] + dist(a, b));
				// 5. 换另一只手来按
				nxt[a] = min(nxt[a], cur[p] + dist(p, b));
			}
			swap(cur, nxt);
		}
		int res = INT_MAX / 2;
		for (int p = 0;p <= 26;p++) res = min(res, cur[p]);
		return res;
	}
private:
	// 键盘按行排列，每行 6 个，距离为曼哈顿距离；空闲手指(26)移动无代价
	int dist(int x, int y) {
		if (x == 26 || y == 26) return 0;
		int x1 = x / 6, y1 = x % 6, x2 = y / 6, y2 = y % 6;
		return abs(x1 - x2) + abs(y1 - y2);
	}
};

//int main() {
//	Solution1320 s;
//	cout << s.minimumDistance("CAKE") << endl; // 3
//	cout << s.minimumDistance("HAPPY") << endl; // 6
//	return 0;
//}
