#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// 辅助函数：去除多余空格
void removeExtraSpaces(string& s) {
    int slow = 0;
    for (int fast = 0; fast < s.size(); ++fast) {
        // 1. 跳过非空格字符
        if (s[fast] != ' ') {
            s[slow++] = s[fast];
        }
        // 2. 遇到空格时，只有当 slow > 0 且前一个字符不是空格时，才保留这个空格
        else if (slow > 0 && s[slow - 1] != ' ') {
            s[slow++] = ' ';
        }
    }
    // 3. 如果最后一个字符是空格，把它去掉
    if (slow > 0 && s[slow - 1] == ' ') {
        slow--;
    }
    // 4. 调整字符串实际长度
    s.resize(slow);
}

class Solution151 {
public:
    string reverseWords(string s) {
        removeExtraSpaces(s);
		int l = s.length();
        if (l <= 1) {
            return s;
        }

        reverse(s.begin(), s.end());
        int reverse_start = 0;
		int reverse_end = 0;
        for (auto it = s.begin();it != s.end();it++) {
            if (*it == ' ') {
                reverse(s.begin() + reverse_start, s.begin() + reverse_end);
                reverse_start = reverse_end + 1;
                reverse_end++;
            }
            else {
                reverse_end++;
            }
        }
        reverse(s.begin() + reverse_start, s.begin() + reverse_end);

        return s;
    }
};

//int main() {
//	Solution151 sol;
//	string input = "  the sky  is blue  "; // Example input
//	string  output = sol.reverseWords(input);
//	cout << "Reversed words: \"" << output << "\"" << endl;
//	return 0;
//}