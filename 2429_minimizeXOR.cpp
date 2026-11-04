#include <iostream>
using namespace std;

class Solution2429 {
public:
    int minimizeXor(int num1, int num2) {
        long long a = num1, b = num2;
        int need = 0;
        for (int i = 0;i < 32;i++) {
            if ((b >> i) & 1LL) need++;
        }

        long long x = 0;
        // 1. 先对齐 num1 的高位 1，能保留的高位尽量保留
        for (int i = 31;i >= 0 && need > 0;i--) {
            if ((a >> i) & 1LL) {
                x |= (1LL << i);
                need--;
            }
        }

        // 2. 还缺 1 时，从低位补 0 位，代价最小
        for (int i = 0;i < 32 && need > 0;i++) {
            if (((a >> i) & 1LL) == 0) {
                x |= (1LL << i);
                need--;
            }
        }

        return (int)x;
    }
};

//int main() {
//	Solution2429 solution;
//	int num1 = 1, num2 = 12;
//	cout << solution.minimizeXor(num1, num2) << endl;
//	return 0;
//}
