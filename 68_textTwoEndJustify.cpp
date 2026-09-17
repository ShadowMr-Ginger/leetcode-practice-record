#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 原先版本的代码
class Solution68 {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> final_ans;
        int n = words.size();
        int surplusWidth = maxWidth;
        int intervals = 0; // 统计单词间的间隔数
        int start_word_idx = 0;
        for (int i = 0; i < n;i++) {
            string currentWord = words[i];
            bool row_full = false;
            bool two_end_justifying = true;
            int tmp = 0;
            if (surplusWidth >= currentWord.size()) {
                surplusWidth -= currentWord.size() + 1;
                if (surplusWidth <= 0) {
                    surplusWidth++;
                    row_full = true;
                    tmp = i + 1;
                    if (i == n - 1) {
                        two_end_justifying = false;
                    }
                }
                else {
                    intervals++;
                }
            }
            else {
                intervals--;
                surplusWidth++;
                row_full = true;
                tmp = i;
            }

            if (i == n - 1 && !row_full) {
                intervals--;
                surplusWidth++;
                row_full = true;
                two_end_justifying = false;
                tmp = i + 1;
            }
            if (intervals == 0) {
                two_end_justifying = false;
            }

            if (row_full && two_end_justifying) {
                int basic_blanks = surplusWidth / intervals + 1;
                int add_blank_nums = surplusWidth % intervals;
                string line = "";
                for (int j = start_word_idx;j < start_word_idx + intervals;j++) {
                    line += words[j];
                    if (add_blank_nums) {
                        add_blank_nums--;
                        for (int k = 0;k < basic_blanks + 1;k++) {
                            line += " ";
                        }
                    }
                    else {
                        for (int k = 0;k < basic_blanks;k++) {
                            line += " ";
                        }
                    }
                }
                line += words[start_word_idx + intervals];
                final_ans.push_back(line);
                intervals = 0;
                surplusWidth = maxWidth;
                start_word_idx = tmp;
                if (tmp == i){
                    i--;
                }
            }
            else if (row_full && !two_end_justifying) {
                string line = "";
                for (int j = start_word_idx;j < start_word_idx + intervals;j++) {
                    line += words[j];
                    line += " ";
                }
                line += words[start_word_idx + intervals];
                for (int j = 0;j < surplusWidth;j++) {
                    line += " ";
                }
                final_ans.push_back(line);
                intervals = 0;
                surplusWidth = maxWidth;
                start_word_idx = tmp;
                if (tmp == i) {
                    i--;
                }
            }
        }
        return final_ans;
    }
};


// AI优化后的代码
class Solution68_PLUS {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // 1. 贪心确定当前行能放多少个单词
            int j = i;
            int lineLen = 0;
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }
            // 此时 words[i...j-1] 是当前行的单词，共 (j - i) 个

            int wordCount = j - i;
            int spaceCount = maxWidth - lineLen; // 需要填充的总空格数
            string line = "";

            // 2. 排版当前行
            if (wordCount == 1 || j == n) {
                // 情况A：只有一个单词，或者是最后一行 -> 左对齐
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " "; // 单词间至少一个空格
                }
                // 剩余空格全部补在末尾
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // 情况B：双端对齐，且单词数 > 1
                int avgSpace = spaceCount / (wordCount - 1);
                int extraSpace = spaceCount % (wordCount - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) { // 最后一个单词后面不加空格
                        int spacesToAdd = avgSpace + (k - i < extraSpace ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }
                }
            }

            res.push_back(line);
            i = j; // 移动到下一行的第一个单词
        }
        return res;
    }
};

//
//int main() {
//	Solution68 sol;
//	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." }; // Example input
//	int maxWidth = 16; // Example max width
//	vector<string> result = sol.fullJustify(words, maxWidth);
//	cout << "Justified text:" << endl;
//	for (const string& line : result) {
//		cout << "\"" << line << "\"" << endl;
//	}
//	return 0;
//}