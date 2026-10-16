#include <iostream>
#include <vector>
using namespace std;

class Solution481 {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        // 1. 先生成字符串：第 i 组的字符由 s[i] 的值决定，组数由 s[i] 的次数决定
        vector<int> s = {1, 2, 2};
        int i = 2;        // 读指针，指向当前组的重复次数
        int num = 1;      // 下一个要填充的字符（1 和 2 交替）
        while ((int)s.size() < n) {
            int cnt = s[i];
            // 2. 按次数追加字符，注意只生成到 n 为止
            for (int j = 0;j < cnt && (int)s.size() < n;j++) {
                s.push_back(num);
            }
            num = 3 - num; // 1 和 2 互换
            i++;
        }
        // 3. 统计前 n 个字符中 1 的个数
        int count = 0;
        for (int k = 0;k < n;k++) {
            if (s[k] == 1) count++;
        }
        return count;
    }
};

//int main() {
//	Solution481 sol;
//	cout << sol.magicalString(6) << endl;   // 3
//	cout << sol.magicalString(1) << endl;   // 1
//	cout << sol.magicalString(10) << endl;  // 4
//	return 0;
//}
