#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
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
	void traverse(TreeNode* root, TreeNode* &previous, int &result) {
		if (!root) return;

		traverse(root->left, previous, result);
		if (previous) {
			result = min(result, abs(root->val - previous->val));
		}
		previous = root;
		traverse(root->right, previous, result);
	}
public:
	int getMinimumDifference(TreeNode* root) {
		int result = INT_MAX;
		TreeNode* previous = NULL;
		traverse(root, previous, result);

		return result;
	}
};
