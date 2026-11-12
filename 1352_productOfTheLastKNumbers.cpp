#include <vector>
#include <iostream>
using namespace std;

class Solution1352 {
public:
    Solution1352() {
        prefix.push_back(1);
    }

    void add(int num) {
        // 遇到 0 后，更早的元素不可能再被非 0 k 乘到，重置前缀积
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        // k 超过上次 0 之后的长度，说明乘积含 0
        if (k >= prefix.size()) {
            return 0;
        }
        // 用后一个前缀积除以前 k+1 个前缀积
        return (int)(prefix.back() / prefix[prefix.size() - 1 - k]);
    }

private:
    vector<long long> prefix;
};

//int main() {
//	Solution1352 obj;
//	obj.add(3);
//	obj.add(0);
//	obj.add(2);
//	obj.add(5);
//	obj.add(4);
//	cout << obj.getProduct(2) << endl;
//	cout << obj.getProduct(3) << endl;
//	cout << obj.getProduct(4) << endl;
//	obj.add(8);
//	cout << obj.getProduct(2) << endl;
//	return 0;
//}
