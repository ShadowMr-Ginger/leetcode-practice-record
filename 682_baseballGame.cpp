#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution682 {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (string& op : operations) {
            if (op == "C") {
                // 移除上一轮得分
                scores.pop();
            } else if (op == "D") {
                // 本轮得分是上一轮的两倍
                scores.push(scores.top() * 2);
            } else if (op == "+") {
                // 本轮得分是前两轮之和
                int top1 = scores.top();
                scores.pop();
                int top2 = scores.top();
                scores.push(top1);
                scores.push(top1 + top2);
            } else {
                // 普通得分，转成整数入栈
                scores.push(stoi(op));
            }
        }
        // 累加栈中所有得分
        int total = 0;
        while (!scores.empty()) {
            total += scores.top();
            scores.pop();
        }
        return total;
    }
};

//int main() {
//	Solution682 solution;
//	vector<string> operations = {"5", "2", "C", "D", "+"};
//	cout << solution.calPoints(operations) << endl;
//	return 0;
//}
