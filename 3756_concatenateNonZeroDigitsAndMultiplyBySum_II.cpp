#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution3756 {
public:
    string concatNonZeroDigitsAndMultiply(string n) {
        string digits;
        int digit_sum = 0;
        // 1. 统计数字和，并拼接非零数字
        for (int i = 0;i < (int)n.size();i++) {
            digit_sum += n[i] - '0';
            if (n[i] != '0') {
                digits += n[i];
            }
        }
        if (digits.empty()) {
            digits = "0";
        }
        // 2. 大数乘以小整数
        return mul(digits, digit_sum);
    }

    long long concatNonZeroDigitsAndMultiply(long long n) {
        long long digits = 0;
        int digit_sum = 0;
        while (n > 0) {
            int d = n % 10;
            digit_sum += d;
            if (d != 0) {
                digits = digits * 10 + d;
            }
            n /= 10;
        }
        return digits * digit_sum;
    }

private:
    string mul(string a, int b) {
        if (b == 0) {
            return "0";
        }
        string res;
        int carry = 0;
        // 从低位到高位做竖式乘法
        for (int i = (int)a.size() - 1;i >= 0;i--) {
            int cur = (a[i] - '0') * b + carry;
            res += char('0' + cur % 10);
            carry = cur / 10;
        }
        while (carry > 0) {
            res += char('0' + carry % 10);
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        int p = 0;
        while (p + 1 < (int)res.size() && res[p] == '0') {
            p++;
        }
        return res.substr(p);
    }
};

//int main() {
//	Solution3756 solution;
//	cout << solution.concatNonZeroDigitsAndMultiply(string("999999999999999999")) << endl;
//	cout << solution.concatNonZeroDigitsAndMultiply(string("1010")) << endl;
//	cout << solution.concatNonZeroDigitsAndMultiply(909LL) << endl;
//	return 0;
//}
