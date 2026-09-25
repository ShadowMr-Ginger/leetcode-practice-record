#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution1324 {
public:
    vector<string> printVertically(string s) {
        // 1. 按空格切分单词
        vector<string> words;
        string word;
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);

        // 2. 找最长单词长度，即输出行数
        int max_len = 0;
        for (auto& w : words) {
            max_len = max(max_len, (int)w.size());
        }

        // 3. 第 j 列：每个单词的第 j 个字符，不足则补空格，末尾空格裁掉
        vector<string> res;
        for (int j = 0;j < max_len;j++) {
            string col;
            for (auto& w : words) {
                if (j < (int)w.size()) col += w[j];
                else col += ' ';
            }
            while (!col.empty() && col.back() == ' ') col.pop_back();
            res.push_back(col);
        }
        return res;
    }
};

//int main() {
//	Solution1324 sol;
//	vector<string> res1 = sol.printVertically("HOW ARE YOU");
//	for (auto& r : res1) cout << "\"" << r << "\" ";
//	cout << endl;
//	vector<string> res2 = sol.printVertically("TO BE OR NOT TO BE");
//	for (auto& r : res2) cout << "\"" << r << "\" ";
//	cout << endl;
//	return 0;
//}
