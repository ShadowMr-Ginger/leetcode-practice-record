#include <iostream>
using namespace std;

class Solution869 {
public:
    bool reorderedPowerOf2(int n) {
        int target[10] = {0};
        count_digits(n, target);

        // 1. 枚举所有不超过 1e9 的 2 的幂
        for (long long p = 1;p <= 1000000000LL;p *= 2) {
            int cur[10] = {0};
            count_digits((int)p, cur);
            // 2. 数字频次一致即可重排得到
            if (same_count(target, cur)) {
                return true;
            }
        }
        return false;
    }

private:
    void count_digits(int x, int cnt[10]) {
        for (int i = 0;i < 10;i++) {
            cnt[i] = 0;
        }
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
    }

    bool same_count(int a[10], int b[10]) {
        for (int i = 0;i < 10;i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};

//int main() {
//	Solution869 solution;
//	cout << solution.reorderedPowerOf2(1) << endl;
//	cout << solution.reorderedPowerOf2(10) << endl;
//	cout << solution.reorderedPowerOf2(46) << endl;
//	return 0;
//}
