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
	TreeNode* merge(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr) return t2;
		if (t2 == nullptr) return t1;

		TreeNode* root = new TreeNode(t1->val + t2->val);
		root->left = this->merge(t1->left, t2->left);
		root->right = this->merge(t1->right, t2->right);

		return root;
	}
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		return this->merge(t1, t2);
	}
};
