#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution1003 {
public:
    bool isValid(string s) {
        // 用栈模拟消除过程，遇到 'c' 时检查栈顶是否为 "ab"
        string st;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == 'c') {
                int n = st.size();
                if (n < 2 || st[n - 2] != 'a' || st[n - 1] != 'b') {
                    return false;
                }
                st.pop_back();
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }
        return st.empty();
    }
};

//int main() {
//	Solution1003 s;
//	cout << s.isValid("aabcbc") << endl;
//	cout << s.isValid("abcabcababab") << endl;
//	cout << s.isValid("abccba") << endl;
//	return 0;
//}
