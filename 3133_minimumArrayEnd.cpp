#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

class Solution3133 {
public:
    long long minEnd(int n, int x) {
        // 把 x 中为 0 的位当作空槽，将 n-1 的二进制逐位填进去
        long long result = x;
        long long mask = x;
        long long remaining = n - 1;
        int bit = 0;
        while (remaining > 0) {
            // 1. 找到 x 中下一个为 0 的位
            while ((mask >> bit & 1) == 1) {
                bit++;
            }
            // 2. remaining 的最低位若为 1，则占用该空槽
            if (remaining & 1) {
                result |= 1LL << bit;
            }
            remaining >>= 1;
            bit++;
        }
        return result;
    }
};

//int main() {
//	Solution3133 solution;
//	cout << solution.minEnd(3, 4) << endl;
//	cout << solution.minEnd(2, 7) << endl;
//	return 0;
//}
