#include <iostream>
#include <vector>
using namespace std;

class Solution717 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        // 1. 从前往后切分，1 开头只能是两比特字符
        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                i += 1;
            }
        }
        // 2. 正好停在最后一位说明末尾是一比特字符
        return i == n - 1;
    }
};

//int main() {
	//Solution717 solution;
	//vector<int> bits = {1, 0, 0};
	//cout << solution.isOneBitCharacter(bits) << endl;
	//return 0;
//}
