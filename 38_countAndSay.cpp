#include <iostream>
#include <string>

using namespace std;

class Solution38 {
public:
	string countAndSay(int n) {
		string s = "1";
		// 从第 1 项开始，逐项朗读生成下一项
		for (int i = 1;i < n;i++) {
			s = countAndSayOnce(s);
		}
		return s;
	}

private:
	// 对当前串做一次报数：连续相同字符 -> 个数 + 字符
	string countAndSayOnce(const string& s) {
		string result;
		int n = s.size();
		for (int i = 0;i < n;) {
			// 找到连续相同字符的结束位置 j
			int j = i;
			while (j < n && s[j] == s[i]) {
				j++;
			}
			// [i, j) 为一段连续相同字符
			result += to_string(j - i);
			result += s[i];
			i = j;
		}
		return result;
	}
};

//int main() {
//	Solution38 solution;
//	cout << solution.countAndSay(1) << endl;
//	cout << solution.countAndSay(4) << endl;
//	return 0;
//}
