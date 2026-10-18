#include <iostream>
#include <string>
using namespace std;

class Solution3274 {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        // 颜色由 (列下标 + 行下标) 的奇偶性决定，直接比较奇偶是否相同
        int color1 = (coordinate1[0] - 'a' + coordinate1[1] - '1') % 2;
        int color2 = (coordinate2[0] - 'a' + coordinate2[1] - '1') % 2;
        return color1 == color2;
    }
};

//int main() {
//	Solution3274 sol;
//	cout << boolalpha << sol.checkTwoChessboards("a1", "c3") << endl;
//	cout << boolalpha << sol.checkTwoChessboards("a1", "h3") << endl;
//	return 0;
//}
