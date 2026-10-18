#include <iostream>
#include <string>

using namespace std;

class Solution1663 {
public:
	string getSmallestString(int n, int k) {
		// 1. 先全部放 'a'，把问题转成每个位置最多还能加多少（最多 +25 变 'z'）
		string result(n, 'a');
		k -= n;
		// 2. 从末尾往前分配增量：越靠后的字符对字典序影响越小，优先放后面
		for (int i = n - 1;i >= 0 && k > 0;i--) {
			int add = min(k, 25);
			result[i] = 'a' + add;
			k -= add;
		}
		return result;
	}
};

//int main() {
//	Solution1663 solution;
//	cout << solution.getSmallestString(3, 27) << endl;
//	cout << solution.getSmallestString(5, 73) << endl;
//	return 0;
//}
