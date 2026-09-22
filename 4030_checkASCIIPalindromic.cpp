#include <iostream>
#include <string>
using namespace std;

class Solution4030 {
public:
    bool checkPalindromic(string s) {
        int left = 0;
        int right = (int)s.size() - 1;
        // 双指针对撞，逐个比较首尾字符的 ASCII 值
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

//int main() {
//	Solution4030 sol;
//	cout << sol.checkPalindromic("aba") << endl;
//	cout << sol.checkPalindromic("abcba") << endl;
//	cout << sol.checkPalindromic("abc") << endl;
//	return 0;
//}
