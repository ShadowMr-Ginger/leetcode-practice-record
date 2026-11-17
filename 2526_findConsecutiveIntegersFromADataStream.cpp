#include <iostream>
using namespace std;

class Solution2526 {
public:
	int target, k; // 目标值和要求的连续次数
	int count; // 当前已连续出现 target 的次数

	Solution2526(int value, int k) {
		this->target = value;
		this->k = k;
		count = 0;
	}

	bool consec(int num) {
		// 等于目标值则计数加一，否则重置为 0
		count = (num == target) ? count + 1 : 0;
		// 连续次数达到 k 才返回 true
		return count >= k;
	}
private:
};

//int main() {
//	Solution2526* data_stream = new Solution2526(4, 3);
//	cout << data_stream->consec(4) << endl; // false
//	cout << data_stream->consec(4) << endl; // false
//	cout << data_stream->consec(4) << endl; // true
//	cout << data_stream->consec(3) << endl; // false
//	cout << data_stream->consec(4) << endl; // false
//	return 0;
//}
