#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

 // 104. Maximum Depth of Binary Tree
 // 递归法，时间复杂度O(n)，空间复杂度O(h)，h为树的高度
class Solution104 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int n = 1 + max(maxDepth(root->right), maxDepth(root->left));
        return n;
    }
};


//int main() {
//	Solution104 solution;
//	TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
//	int depth = solution.maxDepth(root);
//	cout << "Max depth of the tree: " << depth << endl; // Output: 3
//	return 0;
//}