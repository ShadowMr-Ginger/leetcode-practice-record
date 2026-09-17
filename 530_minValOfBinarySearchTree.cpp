

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
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


/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。

*/


// 深度优先搜索 DFS (中序遍历)，时间复杂度O(n)，空间复杂度O(h)，h为树的高度
class Solution530 {
public:
    void dfs(TreeNode* root, int& previous_node_val, int& min_diff) {
        if (root->left != nullptr) {
            dfs(root->left, previous_node_val, min_diff);
        }
        min_diff = min(min_diff, root->val - previous_node_val);
        previous_node_val = root->val;
        if (root->right != nullptr) {
            dfs(root->right, previous_node_val, min_diff);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = numeric_limits<int>::max() / 2;
        int previous_node_val = -diff;
        dfs(root, previous_node_val, diff);

        return diff;
    }
};


// AI优化后的递归方法，使用布尔值标记是否为第一个节点，避免使用哨兵值
class Solution530_PLUS {
public:
    void dfs(TreeNode* root, int& prev_val, bool& first_node, int& min_diff) {
        if (!root) return; // 递归终止条件：空节点直接返回

        // 1. 遍历左子树
        dfs(root->left, prev_val, first_node, min_diff);

        // 2. 处理当前节点
        if (!first_node) {
            // 如果不是第一个节点，才计算差值并更新最小值
            min_diff = min(min_diff, root->val - prev_val);
        }
        // 更新前一个节点的值，并标记已经不是第一个节点了
        prev_val = root->val;
        first_node = false;

        // 3. 遍历右子树
        dfs(root->right, prev_val, first_node, min_diff);
    }

    int getMinimumDifference(TreeNode* root) {
        int min_diff = numeric_limits<int>::max();
        int prev_val = 0;
        bool first_node = true; // 使用布尔值标记是否为第一个节点

        dfs(root, prev_val, first_node, min_diff);

        return min_diff;
    }
};


//int main() {
//	Solution530 solution;
//	TreeNode* root = new TreeNode(4);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(6);
//	root->left->left = new TreeNode(1);
//	root->left->right = new TreeNode(3);
//	int minDiff = solution.getMinimumDifference(root);
//	cout << "Minimum difference: " << minDiff << endl;
//	// Clean up memory
//	delete root->left->left;
//	delete root->left->right;
//	delete root->left;
//	delete root->right;
//	delete root;
//	return 0;
//}