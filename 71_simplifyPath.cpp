/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。

在 Unix 风格的文件系统中规则如下：

一个点 '.' 表示当前目录本身。
此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
返回的 简化路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。



示例 1：

输入：path = "/home/"

输出："/home"

解释：

应删除尾随斜杠。

示例 2：

输入：path = "/home//foo/"

输出："/home/foo"
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;



// 原做法

class Solution71 {
public:
    string simplifyPath(string path) {
        int n = path.length();
        if (n <= 1) {
            return path;
        }

        // 初始化栈
        vector<string>  simplePathSt;

        string next_level = "";

        path += '/';
        n++;

        bool end = false; // 用于记录路径字符录入的状态
        for (int i = 1; i < n; i++) {
            if (!end) {
                if (path[i] == '/') {
                    end = true;
                    // 结算最终路径
                    if (next_level == "..") {
                        if (!simplePathSt.empty()) {
                            simplePathSt.pop_back();
                        }
                        next_level = "";
                    }
                    else if (next_level == "." || next_level.length() == 0) {
                        next_level = "";
                        continue;
                    }
                    else {
                        simplePathSt.push_back(next_level);
                        next_level = "";
                    }
                }
                else {
                    next_level += path[i];
                }
            }
            else {
                //
                if (path[i] == '/') {
                    continue;
                }
                else {
                    end = false;
                    next_level += path[i];
                }
            }
        }


        // 将栈清空
        string ans = "";
        if (simplePathSt.empty()) {
            return "/";
        }
        else {
            for (int i = 0;i < simplePathSt.size();i++) {
                ans += "/" + simplePathSt[i];
            }
        }


        return ans;

    }
};


// AI优化版本，使用 string_view 避免不必要的字符串拷贝，同时逻辑更清晰

class Solution71_PLUS {
public:
    string simplifyPath(string path) {
        // 用 vector 模拟栈，方便最后直接拼接结果
        vector<string> st;
        int n = path.size();

        for (int i = 0; i < n; ) {
            // 1. 遇到斜杠，直接跳过（处理连续的 '//'）
            if (path[i] == '/') {
                i++;
                continue;
            }

            // 2. 提取两个斜杠之间的目录名
            int start = i;
            while (i < n && path[i] != '/') {
                i++;
            }
            // 使用 string_view 零拷贝截取，避免内存分配
            string_view dir(path.data() + start, i - start);

            // 3. 根据目录名执行栈操作
            if (dir == "..") {
                if (!st.empty()) st.pop_back();
            }
            else if (dir != ".") {
                // 非 '.' 且非 '..' 的有效目录名入栈
                // 注意：题目说 '...' 也是有效目录名
                st.push_back(string(dir));
            }
        }

        // 4. 拼接最终结果
        string ans;
        for (const auto& dir : st) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};

// 灵茶山艾府做法

//class Solution {
//public:
//    string simplifyPath(string path) {
//        vector<string> stk;
//        istringstream ss(path); // 使用 views 的代码见【C++ views】
//        string s;
//        while (getline(ss, s, '/')) {
//            if (s.empty() || s == ".") {
//                continue;
//            }
//            if (s != "..") {
//                stk.push_back(s);
//            }
//            else if (!stk.empty()) {
//                stk.pop_back();
//            }
//        }
//
//        string ans;
//        for (string& s : stk) {
//            ans += '/';
//            ans += s;
//        }
//        return stk.empty() ? "/" : ans;
//    }
//};



//int main() {
//	Solution71 solution;
//	string path = "/home/../../..";
//	string simplifiedPath = solution.simplifyPath(path);
//	cout << "Simplified Path: " << simplifiedPath << endl; // Output: "/home/foo"
//	return 0;
//}