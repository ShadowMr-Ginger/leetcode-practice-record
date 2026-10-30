#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution710 {
public:
    Solution710(int n, vector<int>& blacklist) {
        // 1. 白名单数量 = 总数 - 黑名单数量
        int b = blacklist.size();
        valid = n - b;
        unordered_map<int, int> black_set;
        for (int x : blacklist) {
            black_set[x] = 1;
        }

        // 2. 将[0, valid)内的黑名单映射到尾部可用白名单
        int last = n - 1;
        for (int x : blacklist) {
            if (x >= valid) {
                continue;
            }
            while (black_set.count(last)) {
                last--;
            }
            mapping[x] = last;
            last--;
        }
    }

    int pick() {
        int x = rand() % valid;
        // 命中被映射的黑名单，则返回替身；否则直接返回
        if (mapping.count(x)) {
            return mapping[x];
        }
        return x;
    }

private:
    unordered_map<int, int> mapping;
    int valid;
};

//int main() {
//	Solution710 sol(7, vector<int>{2, 3, 5});
//	cout << sol.pick() << endl;
//	return 0;
//}
