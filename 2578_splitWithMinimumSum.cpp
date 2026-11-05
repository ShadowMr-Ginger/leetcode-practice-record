#include <iostream>
using namespace std;

class Solution2578 {
public:
    int splitNum(int num) {
        int freq[10] = {};
        while (num > 0) {
            freq[num % 10]++;
            num /= 10;
        }

        int num1 = 0;
        int num2 = 0;
        bool first = true;
        // 小数字优先，并轮流分给两个数，让高位更小
        for (int d = 0;d < 10;d++) {
            while (freq[d] > 0) {
                if (first) {
                    num1 = num1 * 10 + d;
                } else {
                    num2 = num2 * 10 + d;
                }
                first = !first;
                freq[d]--;
            }
        }
        return num1 + num2;
    }
};

//int main() {
//	Solution2578 sol;
//	cout << sol.splitNum(4325) << endl;
//	cout << sol.splitNum(687) << endl;
//	return 0;
//}
