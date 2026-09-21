#include <iostream>
using namespace std;

class Solution700 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // 1. 利用 BST 性质：小往左，大往右
        while (root != nullptr) {
            if (root->val == val) {
                return root;
            } else if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};

//int main() {
//	TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
//	Solution700 solution;
//	TreeNode* ans = solution.searchBST(root, 2);
//	cout << (ans ? ans->val : -1) << endl;
//	return 0;
//}
