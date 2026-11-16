#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution2695 {
public:
    Solution2695(vector<int>& nums) {
        // 1. 保存数组，同时预计算元素和，供加法使用
        data = nums;
        for (int x : nums) {
            total += x;
        }
    }

    int add(Solution2695& other) {
        // 2. 两个对象相加返回所有元素总和
        return total + other.total;
    }

    string to_string() {
        // 3. 转成 [a,b,c] 格式，逗号后无空格
        string res = "[";
        for (int i = 0;i < (int)data.size();i++) {
            if (i > 0) {
                res += ",";
            }
            res += std::to_string(data[i]);
        }
        res += "]";
        return res;
    }

private:
    vector<int> data;
    int total = 0;
};

//int main() {
//	vector<int> nums1{1, 2};
//	vector<int> nums2{3, 4};
//	Solution2695 obj1(nums1);
//	Solution2695 obj2(nums2);
//	cout << obj1.add(obj2) << endl;
//
//	vector<int> nums3{23, 98, 42, 70};
//	Solution2695 obj3(nums3);
//	cout << obj3.to_string() << endl;
//	return 0;
//}
