#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution13 {
public:
    int romanToInt(string s) {
        // 1. 使用固定数组代替 unordered_map，消除哈希开销
        int charMap[89] = { 0 };
        charMap['I'] = 1;
        charMap['V'] = 5;
        charMap['X'] = 10;
        charMap['L'] = 50;
        charMap['C'] = 100;
        charMap['D'] = 500;
        charMap['M'] = 1000;

        int ans = 0;
        int n = s.length();
        if (n == 0) return 0;

        // 2. 保留你优秀的“前向遍历”逻辑
        int lastValue = charMap[s[0]];
        for (int i = 1; i < n; ++i) {
            int value = charMap[s[i]];
            if (lastValue < value) {
                ans -= lastValue;
            }
            else {
                ans += lastValue;
            }
            lastValue = value;
        }
        // 3. 别忘了加上最后一个字符的值
        ans += lastValue;

        return ans;
    }
};

//int main() {
//	Solution13 sol;
//	string roman = "MCMXCIV"; // Example input
//	int result = sol.romanToInt(roman);
//	cout << "The integer value of Roman numeral " << roman << " is: " << result << endl;
//	return 0;
//}