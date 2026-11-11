#include <iostream>
#include <string>
using namespace std;

class Solution678 {
public:
    bool checkValidString(string s) {
        int n = s.size();
        // lo 表示最少还剩多少个未匹配的左括号，hi 表示最多还剩多少个
        int lo = 0, hi = 0;
        for (int i = 0;i < n;i++) {
            char c = s[i];
            if (c == '(') {
                lo++; hi++;
            } else if (c == ')') {
                lo--; hi--;
            } else { // '*' 可当 '('、')' 或空
                lo--; hi++;
            }
            if (hi < 0) return false; // 右括号太多，无法匹配
            lo = max(lo, 0); // 左括号最少不能为负，'*' 可当空串
        }
        return lo == 0; // 存在一种匹配使左括号恰好用完
    }
};

//int main() {
//	Solution678 sol;
//	cout << sol.checkValidString("()") << endl;        // 1
//	cout << sol.checkValidString("(*)") << endl;       // 1
//	cout << sol.checkValidString("(*))") << endl;      // 1
//	cout << sol.checkValidString("((**") << endl;      // 1
//	cout << sol.checkValidString("((*))") << endl;     // 0
//	return 0;
//}
