#include <iostream>
#include <stack>
using namespace std;

class Solution232 {
public:
    void push(int x) {
        input_stack.push(x);
    }

    int pop() {
        ensure_output();
        int front = output_stack.top();
        output_stack.pop();
        return front;
    }

    int peek() {
        ensure_output();
        return output_stack.top();
    }

    bool empty() {
        return input_stack.empty() && output_stack.empty();
    }

private:
    stack<int> input_stack;
    stack<int> output_stack;

    // 输出栈为空时，把输入栈整体倒过来，让队首位于栈顶
    void ensure_output() {
        if (output_stack.empty()) {
            while (!input_stack.empty()) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
        }
    }
};

//int main() {
//	Solution232 q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	cout << q.pop() << endl;
//	cout << q.peek() << endl;
//	cout << q.empty() << endl;
//	return 0;
//}
