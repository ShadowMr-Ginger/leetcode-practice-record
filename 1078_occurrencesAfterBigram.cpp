#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution1078 {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // 1. 按空格切分单词
        vector<string> words;
        istringstream iss(text);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        // 2. 找连续出现 first、second 时的下一个单词
        vector<string> res;
        for (int i = 0;i + 2 < (int)words.size();i++) {
            if (words[i] == first && words[i + 1] == second) {
                res.push_back(words[i + 2]);
            }
        }
        return res;
    }
};

//int main() {
//	Solution1078 solution;
//	vector<string> res = solution.findOcurrences("alice is a good girl she is a good student", "a", "good");
//	for (string s : res) {
//		cout << s << " ";
//	}
//	cout << endl;
//	return 0;
//}
