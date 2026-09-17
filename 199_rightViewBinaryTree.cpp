/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。



示例 1：

输入：root = [1,2,3,null,5,null,4]

输出：[1,3,4]

解释：



示例 2：

输入：root = [1,2,3,4,null,null,null,5]

输出：[1,3,4,5]

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



// 原方法 BFS 右子树优先

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
class Solution199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS 右子树优先 
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({ root,1 });
        int current_depth = 0;


        while (!q.empty()) {
            int front_depth = q.front().second;
            TreeNode* current_node = q.front().first;
            q.pop();
            if (front_depth > current_depth) {
                current_depth = front_depth;
                ans.push_back(current_node->val);
            }
            if (current_node->right != nullptr) {
                q.push({ current_node->right, front_depth + 1 });
            }
            if (current_node->left != nullptr) {
                q.push({ current_node->left, front_depth + 1 });
            }
        }
        return ans;

    }
};

// AI优化方法 ，记录queue的size，按层遍历，最后一个节点就是右视图能看到的节点，消除了深度的概念以及pair的数据结构，内存占用更小，代码更简洁
class Solution199_PLUS {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // 记录当前层的节点数量
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // 如果是当前层的最后一个节点，就是右视图能看到的
                if (i == levelSize - 1) {
                    ans.push_back(node->val);
                }

                // 按照常规顺序（先左后右）入队
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};



//int main() {
//	Solution199 solution;
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->right = new TreeNode(5);
//	root->right->right = new TreeNode(4);
//	vector<int> result = solution.rightSideView(root);
//	for (int val : result) {
//		cout << val << " ";
//	}
//	cout << endl;
//	return 0;
//}