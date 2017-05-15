#include <stdio.h>
#include <algorithm>
#include <stack>
#include <climits>

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
struct StackNode {
	TreeNode* node;
	int depth;

	StackNode(TreeNode* node, int depth) : node(node), depth(depth) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;

		int result = INT_MAX;
		stack<StackNode> s;
		s.push(StackNode(root, 1));
		while (!s.empty()) {
			StackNode sn = s.top();
			s.pop();

			if (sn.node->left) s.push(StackNode(sn.node->left, sn.depth + 1));
			if (sn.node->right) s.push(StackNode(sn.node->right, sn.depth + 1));
			if (!sn.node->left && !sn.node->right) result = min(result, sn.depth);
		}

		return result;
	}
};
