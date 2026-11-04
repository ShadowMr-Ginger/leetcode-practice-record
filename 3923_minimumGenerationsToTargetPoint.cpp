#include <iostream>
#include <numeric>
using namespace std;

class Solution3923 {
public:
    long long minGenerations(int target_x, int target_y) {
        long long x = target_x;
        long long y = target_y;

        // 起点是 (1,1)，且每次操作保持 gcd 不变
        if (x < 1 || y < 1 || gcd(x, y) != 1) {
            return -1;
        }

        long long ans = 0;
        // 反向用欧几里得除法回退到 (1,1)
        while (x != 1 || y != 1) {
            if (x > y) {
                ans += x / y;
                x %= y;
                // 整除时会多算一步，退回上一格
                if (x == 0) {
                    x = y;
                    ans--;
                }
            } else {
                ans += y / x;
                y %= x;
                if (y == 0) {
                    y = x;
                    ans--;
                }
            }
        }
        return ans;
    }
};

//int main() {
//	Solution3923 sol;
//	cout << sol.minGenerations(3, 2) << endl;
//	cout << sol.minGenerations(5, 1) << endl;
//	cout << sol.minGenerations(2, 2) << endl;
//	return 0;
//}
