/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。



示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <array>
#include <numeric>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution230 {
private:
    int target;
public:
    void myKthSmallest(TreeNode* root, int& crt_cnt, int& ans, bool& found) {
        if (root->left != nullptr) {
            myKthSmallest(root->left, crt_cnt, ans, found);
            if (found) {
                return;
            }
        }
        crt_cnt++;
        if (crt_cnt == target) {
            ans = root->val;
            found = true;
            return;
        }
        if (root->right != nullptr) {
            myKthSmallest(root->right, crt_cnt, ans, found);
            if (found) {
                return;
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        int ans = 0;

        int crt_cnt = 0;
        bool found = false;
        myKthSmallest(root, crt_cnt, ans, found);
        return ans;
    }
};


//int main() {
//	// 构建二叉搜索树
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(1);
//	root->right = new TreeNode(4);
//	root->left->right = new TreeNode(2);
//	Solution230 solution;
//	int k = 1;
//	int result = solution.kthSmallest(root, k);
//	cout << "The " << k << "th smallest element is: " << result << endl;
//	// 释放内存
//	delete root->left->right;
//	delete root->left;
//	delete root->right;
//	delete root;
//	return 0;
//}