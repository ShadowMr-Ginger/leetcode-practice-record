
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;


// 原做法
class MinStack {
public:
    MinStack() {

    }

    void push(int value) {
        common_st.push(value);
        if (min_st.empty() || value <= min_st.top()) {
            min_st.push(value);
        }
    }

    void pop() {
        int value = common_st.top();
        common_st.pop();
        if (value == min_st.top()) {
            min_st.pop();
        }
    }

    int top() {
        return(common_st.top());
    }

    int getMin() {
        return(min_st.top());
    }

private:
    stack<int> common_st;
    stack<int> min_st;
};


// 




//int main() {
//	MinStack* obj = new MinStack();
//	obj->push(-2);
//	obj->push(0);
//	obj->push(-3);
//	cout << "Minimum: " << obj->getMin() << endl; // Returns -3
//	obj->pop();
//	cout << "Top: " << obj->top() << endl;    // Returns 0
//	cout << "Minimum: " << obj->getMin() << endl; // Returns -2
//	delete obj;
//	return 0;
//}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */