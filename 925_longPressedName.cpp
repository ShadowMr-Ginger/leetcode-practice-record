#include <iostream>
#include <string>

using namespace std;

class Solution925 {
public:
	bool isLongPressedName(string name, string typed) {
		int n = name.size();
		int m = typed.size();
		int j = 0;// name 的指针
		for (int i = 0;i < m;i++) {
			if (j < n && typed[i] == name[j]) {
				// 当前字符匹配，两个指针同时前进
				j++;
			} else if (i > 0 && typed[i] == typed[i - 1]) {
				// 与上一个字符相同，视为长按多打的字符，跳过
				continue;
			} else {
				return false;
			}
		}
		// name 必须全部匹配完才算合法
		return j == n;
	}
};

//int main() {
//	Solution925 s;
//	cout << s.isLongPressedName("alex", "aaleex") << endl; // 1
//	cout << s.isLongPressedName("saeed", "ssaaedd") << endl; // 0
//	return 0;
//}
