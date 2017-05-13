#include <cstdio>
#include <cstdint>
#include <climits>
#include <stack>

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
	int64_t min;
	int64_t max;

	StackNode(TreeNode* node, int64_t min, int64_t max) : node(node), min(min), max(max) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;

		stack<StackNode> s;
		s.push(StackNode(root, LONG_MIN, LONG_MAX));

		while (!s.empty()) {
			StackNode sn = s.top();
			s.pop();

			int val = sn.node->val;
			if (!(sn.min < val && val < sn.max)) {
				return false;
			}

			if (sn.node->left) s.push(StackNode(sn.node->left, sn.min, val));
			if (sn.node->right) s.push(StackNode(sn.node->right, val, sn.max));
		}

		return true;
	}
};
