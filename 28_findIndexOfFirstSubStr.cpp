#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution28 {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

//int main() {
//	Solution28 sol;
//	string haystack = "hello"; // Example haystack
//	string needle = "ll"; // Example needle
//	int result = sol.strStr(haystack, needle);
//	cout << "The index of the first occurrence of \"" << needle << "\" in \"" << haystack << "\" is: " << result << endl;
//	return 0;
//}