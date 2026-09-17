#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]

*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// 原递归方法,复杂度为O(n^2)，因为每次都要在中序遍历中查找根节点的位置

class Solution105 {
public:
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int preorder_lp, int preorder_rp, int inorder_lp, int inorder_rp) {
        // 若为叶子节点
        if (preorder_lp == preorder_rp) {
            return new TreeNode(preorder[preorder_lp]);
        }
        // 否则构建子树
        int root_val = preorder[preorder_lp];
        TreeNode* root = new TreeNode(root_val);
        // 匹配根节点，确定左右子树
        int root_idx_inorder = -1;
        for (int i = inorder_lp;i <= inorder_rp;i++) {
            if (inorder[i] == root_val) {
                root_idx_inorder = i;
                break;
            }
        }
        int left_node_number = root_idx_inorder - inorder_lp;
        int right_node_number = inorder_rp - root_idx_inorder;
        // 构建左子树
        if (left_node_number != 0) {
            root->left = buildSubTree(preorder, inorder, preorder_lp + 1, preorder_rp + left_node_number, inorder_lp, root_idx_inorder - 1);
        }
        // 构建右子树
        if (right_node_number != 0) {
            root->right = buildSubTree(preorder, inorder, preorder_lp + left_node_number + 1, preorder_rp, root_idx_inorder + 1, inorder_rp);
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildSubTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};


//  AI优化后的递归方法，使用哈希表优化查找根节点在中序遍历中的位置 复杂度降低到O(n)

class Solution105_PLUS {
private:
    // 使用 unordered_map 存储中序遍历的值到索引的映射，实现 O(1) 查找
    unordered_map<int, int> inOrderMap;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        // 1. 预处理：构建哈希表
        for (int i = 0; i < n; ++i) {
            inOrderMap[inorder[i]] = i;
        }
        // 2. 启动递归
        return buildSubTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder,
        int preL, int preR, int inL, int inR) {
        // 统一的递归出口：当区间无效时，返回空指针
        if (preL > preR || inL > inR) {
            return nullptr;
        }

        // 1. 前序遍历的第一个元素就是当前子树的根
        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        // 2. O(1) 时间从哈希表中获取根节点在中序遍历中的位置
        int rootIdxInInorder = inOrderMap[rootVal];

        // 3. 计算左子树的节点数量
        int leftSize = rootIdxInInorder - inL;

        // 4. 递归构建左子树和右子树
        // 左子树：前序 [preL+1, preL+leftSize], 中序 [inL, rootIdxInInorder-1]
        root->left = buildSubTree(preorder, inorder, preL + 1, preL + leftSize, inL, rootIdxInInorder - 1);

        // 右子树：前序 [preL+leftSize+1, preR], 中序 [rootIdxInInorder+1, inR]
        root->right = buildSubTree(preorder, inorder, preL + leftSize + 1, preR, rootIdxInInorder + 1, inR);

        return root;
    }
};


//int main() {
//	Solution105 solution;
//	vector<int> preorder = { 3, 9, 20, 15, 7 };
//	vector<int> inorder = { 9, 3, 15, 20, 7 };
//	TreeNode* root = solution.buildTree(preorder, inorder);
//	// 输出根节点的值
//	cout << "Root value: " << root->val << endl; // Output: 3
//	return 0;
//}