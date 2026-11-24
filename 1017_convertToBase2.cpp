#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution1017 {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        string res;
        // 模拟短除法，基数为 -2
        while (n != 0) {
            int rem = n % -2;
            n /= -2;
            // 余数为负时转正，并给商加 1 补偿
            if (rem < 0) {
                rem += 2;
                n += 1;
            }
            res.push_back('0' + rem);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//int main() {
//	Solution1017 sol;
//	cout << sol.baseNeg2(2) << endl;
//	cout << sol.baseNeg2(3) << endl;
//	cout << sol.baseNeg2(4) << endl;
//	return 0;
//}
