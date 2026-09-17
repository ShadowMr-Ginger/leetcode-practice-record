#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 行数为n
// 第一行和最后一行，以2* （n - 1）为间隔，一个间隔周期一个数
// 中间第i行，以2 * （n - i） 和 2 * （i - 1）为间隔，一个2 * （n - 1）间隔周期两个数。


class Solution6 {
public:
    string convert(string s, int numRows) {
		// 1. 特殊情况处理
        if (numRows == 1) {
            return s;
        }
		int n = s.length();
        if (n <= numRows) {
            return s;
        }

        // 2. Initialize
        string ans = s;
        int pt = -1;

		// 3. First Line
		for (int i = 0; i < n; i += 2 * numRows - 2) {
			ans[++pt] = s[i];
		}

		// 4. Middle Lines
		for (int i = 1; i < numRows - 1; ++i) {
			for (int j = 0; j < n; j += 2 * numRows - 2) {
				if (j + i < n) {
					ans[++pt] = s[j + i];
				}
				if (j + 2 * numRows - 2 - i < n) {
					ans[++pt] = s[j + 2 * numRows - 2 - i];
				}
			}
		}

		// 5. Last Line
		for (int i = numRows - 1; i < n; i += 2 * numRows - 2) {
			ans[++pt] = s[i];
		}
        
        return ans;
    }
};

//int main() {
//	Solution6 sol;
//	string input = "PAYPALISHIRING"; // Example input
//	int numRows = 3; // Example number of rows
//	string output = sol.convert(input, numRows);
//	cout << "The converted string is: " << output << endl;
//	return 0;
//}