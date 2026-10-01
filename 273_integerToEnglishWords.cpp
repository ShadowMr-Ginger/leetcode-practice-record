#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution273 {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result;
        // 1. 按 Billion、Million、Thousand 分段拆分
        if (num >= 1000000000) {
            result = helper(num / 1000000000) + " Billion";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            if (!result.empty()) result += " ";
            result += helper(num / 1000000) + " Million";
            num %= 1000000;
        }
        if (num >= 1000) {
            if (!result.empty()) result += " ";
            result += helper(num / 1000) + " Thousand";
            num %= 1000;
        }
        if (num > 0) {
            if (!result.empty()) result += " ";
            result += helper(num);
        }
        return result;
    }
private:
    string helper(int num) {
        // 处理 1 到 999，逐位翻译成单词
        vector<string> less_than_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        if (num >= 100) {
            res = less_than_20[num / 100] + " Hundred";
            num %= 100;
        }
        if (num >= 20) {
            if (!res.empty()) res += " ";
            res += tens[num / 10];
            num %= 10;
        } else if (num >= 10) {
            if (!res.empty()) res += " ";
            res += less_than_20[num];
            num = 0;
        }
        if (num > 0) {
            if (!res.empty()) res += " ";
            res += less_than_20[num];
        }
        return res;
    }
};

//int main() {
//	Solution273 solution;
//	cout << solution.numberToWords(123) << endl;
//	cout << solution.numberToWords(12345) << endl;
//	cout << solution.numberToWords(1234567) << endl;
//	cout << solution.numberToWords(0) << endl;
//	return 0;
//}
