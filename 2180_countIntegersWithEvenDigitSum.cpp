#include <iostream>

using namespace std;

class Solution2180 {
public:
    int countEven(int num) {
        int cnt = 0;
        for (int i = 1;i <= num;i++) {
            int sum = 0, x = i;
            // 累加各位数字之和
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            if (sum % 2 == 0) cnt++;
        }
        return cnt;
    }
};

//int main() {
//	Solution2180 solution;
//	cout << solution.countEven(4) << endl;	// 2
//	cout << solution.countEven(30) << endl;	// 14
//	return 0;
//}
