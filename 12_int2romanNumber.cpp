#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const pair<int, string> vS[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution12 {
public:
    string intToRoman(int num) {
        string roman;
        for (int i = 0;i < 13;i++) {
            while (num >= vS[i].first) {
                num -= vS[i].first;
                roman += vS[i].second;
            }
        }
        return roman;
    }
};

//int main() {
//	Solution12 sol;
//	int number = 1994; // Example input
//	string result = sol.intToRoman(number);
//	cout << "The Roman numeral representation of " << number << " is: " << result << endl;
//	return 0;
//}