#include <stdio.h>
#include <algorithm>
#include <limits.h>

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
	int computeMaxPath(TreeNode* root, int& result) {
		if (!root) {
			return 0;
		}

		int leftSum = this->computeMaxPath(root->left, result);
		int rightSum = this->computeMaxPath(root->right, result);

		int maxSum = root->val;
		int maxPath = root->val;
		if (leftSum > 0) {
			maxSum += leftSum;
			maxPath = max(maxPath, root->val + leftSum);
		}
		if (rightSum > 0) {
			maxSum += rightSum;
			maxPath = max(maxPath, root->val + rightSum);
		}

		result = max(result, maxSum);
		return maxPath;
	}
public:
	int maxPathSum(TreeNode* root) {
		int result = INT_MIN;

		this->computeMaxPath(root, result);

		return result;
	}
};
