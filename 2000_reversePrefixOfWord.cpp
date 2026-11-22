#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution2000 {
public:
    string reversePrefix(string word, char ch) {
        // 找到 ch 第一次出现的位置
        int pos = word.find(ch);
        if (pos == string::npos) {
            return word;
        }
        // 2. 反转下标 [0, pos] 的前缀部分
        reverse(word.begin(), word.begin() + pos + 1);
        return word;
    }
};

//int main() {
//	Solution2000 solution;
//	cout << solution.reversePrefix("abcdefd", 'd') << endl;
//	cout << solution.reversePrefix("xyxzxe", 'z') << endl;
//	cout << solution.reversePrefix("abcd", 'z') << endl;
//	return 0;
//}
