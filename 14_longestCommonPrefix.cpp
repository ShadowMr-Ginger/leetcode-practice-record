#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        else if (n == 1)
        {
            return strs[0];
        }

        string prefix = "";
        int m = strs[0].length();
        for (int i = 0;i < m;i++) {
            char current_letter = strs[0][i];
            bool all_the_same = true;
            for (int j = 1;j < n;j++) {
                int l = strs[j].length() - 1;
                if (i > l || current_letter != strs[j][i]) {
                    all_the_same = false;
                    break;
                }
            }
            if (all_the_same) {
                prefix += current_letter;
            }
            else {
                break;
            }
        }
        return prefix;
    }
};

//int main() {
//	Solution14 sol;
//	vector<string> strs = { "flower", "flow", "flight" }; // Example input
//	string result = sol.longestCommonPrefix(strs);
//	cout << "The longest common prefix is: " << result << endl;
//	return 0;
//}