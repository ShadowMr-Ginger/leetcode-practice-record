
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。



示例 1:


输入：inorder = [9, 3, 15, 20, 7], postorder = [9, 15, 7, 20, 3]
输出：[3, 9, 20, null, null, 15, 7]
示例 2 :

	输入：inorder = [-1], postorder = [-1]
	输出：[-1]
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 原做法，使用了unordered_map来存储中序遍历的值到索引的映射，实现 O(1) 查找根节点在中序遍历中的位置，从而优化了时间复杂度到 O(n)
class Solution106 {
private:
    unordered_map<int, int> in_mp;
public:
    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int in_lpt, int in_rpt, int post_lpt, int post_rpt) {
        TreeNode* root = new TreeNode(postorder[post_rpt]);
        if (post_lpt == post_rpt) {
            return root;
        }
        int midIdx = in_mp[postorder[post_rpt]];
        int left_size = midIdx - in_lpt;
        int right_size = in_rpt - midIdx;
        if (right_size > 0) {
            root->right = myBuildTree(inorder, postorder, in_rpt - right_size + 1, in_rpt, post_rpt - right_size, post_rpt - 1);
        }
        if (left_size > 0) {
            root->left = myBuildTree(inorder, postorder, in_lpt, in_lpt + left_size - 1, post_lpt, post_lpt + left_size - 1);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) {
            return nullptr;
        }
        for (int i = 0;i < n;i++) {
            in_mp[inorder[i]] = i;
        }
        TreeNode* ans = myBuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
        return ans;
    }
};


// AI优化后的递归方法
class Solution106_PLUS {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return nullptr;

        // 1. 将哈希表定义为局部变量，避免类成员变量的内存残留
        unordered_map<int, int> in_mp;
        in_mp.reserve(n); // 预分配空间，避免哈希表动态扩容
        for (int i = 0; i < n; ++i) {
            in_mp[inorder[i]] = i;
        }

        // 2. 调用核心递归函数
        return build(inorder, postorder, 0, n - 1, 0, n - 1, in_mp);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
        int in_lpt, int in_rpt, int post_lpt, int post_rpt,
        unordered_map<int, int>& in_mp) {

        // 3. 采用最标准的递归终止条件：区间无效时返回 nullptr
        if (post_lpt > post_rpt) {
            return nullptr;
        }

        // 4. 创建当前子树的根节点
        int root_val = postorder[post_rpt];
        TreeNode* root = new TreeNode(root_val);

        // 5. 计算左右子树的大小
        int mid_idx = in_mp[root_val];
        int left_size = mid_idx - in_lpt;
        int right_size = in_rpt - mid_idx;

        // 6. 递归构建左右子树（即使 size 为 0，递归函数内部也会处理）
        root->left = build(inorder, postorder, in_lpt, mid_idx - 1, post_lpt, post_lpt + left_size - 1, in_mp);
        root->right = build(inorder, postorder, mid_idx + 1, in_rpt, post_rpt - right_size, post_rpt - 1, in_mp);

        return root;
    }
};



//int main() {
//	Solution106 solution;
//	vector<int> inorder = { 9, 3, 15, 20, 7 };
//	vector<int> postorder = { 9, 15, 7, 20, 3 };
//	TreeNode* root = solution.buildTree(inorder, postorder);
//	// 输出根节点的值
//	cout << "Root value: " << root->val << endl; // Output: 3
//	return 0;
//}