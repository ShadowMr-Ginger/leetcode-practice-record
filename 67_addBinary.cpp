#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution67 {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        // 从低位向高位逐位相加
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back('0' + sum % 2);
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//int main() {
//	Solution67 solution;
//	cout << solution.addBinary("11", "1") << endl;
//	cout << solution.addBinary("1010", "1011") << endl;
//	return 0;
//}
