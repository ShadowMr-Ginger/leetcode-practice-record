#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2126 {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // 1. 从小到大排序，先吃小的
        sort(asteroids.begin(), asteroids.end());
        // 2. 质量可能溢出 int，用 long long
        long long cur = mass;
        for (int i = 0;i < asteroids.size();i++) {
            // 3. 当前质量不足以摧毁，必然失败
            if (cur < asteroids[i]) {
                return false;
            }
            cur += asteroids[i];
        }
        return true;
    }
};

//int main() {
//	Solution2126 solution;
//	int mass = 10;
//	vector<int> asteroids = {3, 9, 19, 5, 21};
//	cout << solution.asteroidsDestroyed(mass, asteroids) << endl;
//	return 0;
//}
