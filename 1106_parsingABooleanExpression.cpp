#include <iostream>
#include <string>

using namespace std;

class Solution1106 {
private:
    string expr;
    int idx;

    // 递归解析从 idx 开始的子表达式
    bool parse() {
        char c = expr[idx++];

        if (c == 't') return true;
        if (c == 'f') return false;

        if (c == '!') {
            idx++; // 跳过左括号
            bool val = parse();
            idx++; // 跳过右括号
            return !val;
        }

        // 处理 &( 或 |(
        idx++;
        bool ans = (c == '&');
        while (expr[idx] != ')') {
            bool cur = parse();
            if (c == '&') ans = ans && cur;
            else ans = ans || cur;
            if (expr[idx] == ',') idx++;
        }
        idx++; // 跳过右括号
        return ans;
    }

public:
    bool parseBoolExpr(string expression) {
        expr = expression;
        idx = 0;
        return parse();
    }
};

//int main() {
//	Solution1106 solution;
//	cout << solution.parseBoolExpr("&(|(f))") << endl;
//	cout << solution.parseBoolExpr("|(f,f,f,t)") << endl;
//	cout << solution.parseBoolExpr("!(&(f,t))") << endl;
//	return 0;
//}
