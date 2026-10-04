#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution1362 {
public:
    vector<int> closestDivisors(int num) {
        // 1. 分别计算 num+1 和 num+2 的最接近因数对
        vector<int> res1 = closestPair(num + 1);
        vector<int> res2 = closestPair(num + 2);
        // 2. 返回两数差值更小的一对
        if (res1[1] - res1[0] <= res2[1] - res2[0]) {
            return res1;
        }
        return res2;
    }

private:
    // 从 sqrt(n) 往下找第一个能整除 n 的数，此时两个因数最接近
    vector<int> closestPair(int n) {
        for (int i = (int)sqrt(n);i >= 1;i--) {
            if (n % i == 0) {
                return {i, n / i};
            }
        }
        return {1, n};
    }
};

//int main() {
//	Solution1362 solution;
//	vector<int> res = solution.closestDivisors(8);
//	cout << res[0] << " " << res[1] << endl;
//	res = solution.closestDivisors(123);
//	cout << res[0] << " " << res[1] << endl;
//	return 0;
//}
