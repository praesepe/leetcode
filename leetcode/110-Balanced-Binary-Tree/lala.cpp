#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
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
	int depth(TreeNode* root) {
		if (!root) {
			return 0;
		}

		int leftDepth = this->depth(root->left);
		int rightDepth = this->depth(root->right);

		if (leftDepth == -1 || rightDepth == -1) {
			return -1;
		} else if (1 < abs(leftDepth - rightDepth)) {
			return -1;
		}

		return 1 + max(leftDepth, rightDepth);
	}
public:
	bool isBalanced(TreeNode* root) {
		return this->depth(root) != -1;
	}
};
