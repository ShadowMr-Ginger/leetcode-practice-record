#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        int ls = 0;

        for (int lt = 0;lt < t.length();lt++) {
            if (s[ls] == t[lt]) {
                ls++;
                if (ls == s.length()) {
                    return true;
                }
            }
        }
        if (ls == s.length()) {
            return true;
        }

        return(false);
    }
};


//int main() {
//    string s = "";
//    string t = "A man, a plan, a canal: Panama";
//	Solution392 sol;
//	sol.isSubsequence(s, t) ? cout << "true" : cout << "false";
//}