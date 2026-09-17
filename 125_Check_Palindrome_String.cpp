#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution125 {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // 1. 左指针跳过非字母数字字符
            // isalnum() 判断是否为字母或数字
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // 2. 右指针跳过非字母数字字符
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // 3. 此时左右指针都指向有效字符，统一转小写后比较
            // tolower() 将大写字母转为小写
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // 4. 指针向中间靠拢
            left++;
            right--;
        }

        return true;
    }
};


//int main() {
//    string s = "A man, a plan, a canal: Panama";
//	Solution125 sol;
//	sol.isPalindrome(s) ? cout << "true" : cout << "false";
//}