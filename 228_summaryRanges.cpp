
/*

代码
测试用例
测试用例
测试结果


228. 汇总区间
简单
相关标签
premium lock icon
相关企业
给定一个  无重复元素 的 有序 整数数组 nums 。

区间 [a,b] 是从 a 到 b（包含）的所有整数的集合。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个区间但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;



class Solution228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }

        vector<string> ans;

        bool successive = false;
        int end_number = nums[0];
        string current_interval = to_string(nums[0]);

        for (int i = 1;i < n;i++) {
            if (!successive && nums[i] == nums[i - 1] + 1) {
                successive = true;
                current_interval += "->";
                end_number = nums[i];
            }
            else if (successive && nums[i] != nums[i - 1] + 1) {
                current_interval += to_string(end_number);
                ans.push_back(current_interval);
                successive = false;
                current_interval = to_string(nums[i]);
                end_number = nums[i];
            }
            else if (!successive && nums[i] != nums[i - 1] + 1) {
                ans.push_back(current_interval);
                current_interval = to_string(nums[i]);
                end_number = nums[i];
            }
            else {
                end_number = nums[i];
            }
        }

        if (successive) {
            ans.push_back(current_interval + to_string(end_number));
        }
        else {
            ans.push_back(to_string(end_number));
        }

        return ans;
    }
};

//int main() {
//	Solution228 solution;
//	vector<int> nums = { 0,2,3,4,6,8,9 };
//	vector<string> result = solution.summaryRanges(nums);
//	for (const string& range : result) {
//		cout << range << " ";
//	}
//	cout << endl;
//	return 0;
//}