#include <iostream>
#include <cmath>
using namespace std;

class Solution319 {
public:
    int bulbSwitch(int n) {
        // 1. 第 k 盏灯被切换的次数等于 k 的因子个数
        // 2. 只有完全平方数有奇数个因子，最终会亮
        return (int)sqrt(n);
    }
};

//int main() {
//	Solution319 solution;
//	cout << solution.bulbSwitch(3) << endl;
//	return 0;
//}
