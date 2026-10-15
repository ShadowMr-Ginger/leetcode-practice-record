#include <iostream>

using namespace std;

class Solution374 {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        // 1. 二分查找目标数字
        while (left <= right) {
            // 2. 防溢出取中点
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            } else if (res > 0) {
                left = mid + 1; // 猜小了，往右半找
            } else {
                right = mid - 1; // 猜大了，往左半找
            }
        }
        return -1;
    }
};

//int pick = 6;
//// 模拟 LeetCode 提供的 guess 接口
//int guess(int num) {
//	if (num > pick) return -1;
//	if (num < pick) return 1;
//	return 0;
//}
//int main() {
//	Solution374 sol;
//	cout << sol.guessNumber(10) << endl;
//	return 0;
//}
