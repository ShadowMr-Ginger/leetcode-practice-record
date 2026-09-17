#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution58 {
public:
    int lengthOfLastWord(string s) {
        int l = s.length();
        if (l == 0) return 0;

        int len = 0;
        // 从后往前遍历
        for (int i = l - 1; i >= 0; i--) {
            // 1. 如果还没开始计数，且当前是空格，直接跳过
            if (len == 0 && s[i] == ' ') {
                continue;
            }

            // 2. 如果当前不是空格，说明在单词内部，长度 +1
            if (s[i] != ' ') {
                len++;
            }
            else {
                // 3. 如果已经在单词内部（len > 0），且遇到了空格，说明单词结束
                break;
            }
        }
        return len;
    }
};

//int main() {
//	Solution58 sol;
//	string input = "Hello World"; // Example input
//	int result = sol.lengthOfLastWord(input);
//	cout << "The length of the last word in \"" << input << "\" is: " << result << endl;
//	return 0;
//}