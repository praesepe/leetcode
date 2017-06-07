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
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) {
			return NULL;
		}

		TreeNode* itl = invertTree(root->right);
		TreeNode* itr = invertTree(root->left);

		root->left = itl;
		root->right = itr;

		return root;
	}
};
