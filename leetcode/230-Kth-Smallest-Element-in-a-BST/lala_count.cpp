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
    int getCount(TreeNode* root) {
		if (!root) return 0;

		return 1 + this->getCount(root->left) + this->getCount(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
		int target = this->getCount(root->left) + 1;
		if (k == target) {
			return root->val;
		} else if (k > target) {
			return this->kthSmallest(root->right, k - target);
		}

		return this->kthSmallest(root->left, k);
    }
};
