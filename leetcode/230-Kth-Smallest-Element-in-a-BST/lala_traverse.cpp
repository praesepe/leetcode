#include <stdio.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool findSolution(TreeNode* root, int &k, int& result) {
		if (!root) return false;
		if (this->findSolution(root->left, k, result)) return true;

		k = k - 1;
		result = root->val;
		return k == 0 || this->findSolution(root->right, k, result);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;

		this->findSolution(root, k, result);
		return result;
	}
};
