#include <stack>
#include <vector>

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

struct SearchNode {
	TreeNode* node;
	size_t level;

	SearchNode(TreeNode* node, size_t level) {
		this->node = node;
		this->level = level;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		stack<SearchNode> s;

		vector<vector<int>> result;
		if (root) s.push(SearchNode(root, 0));

		while (!s.empty()) {
			SearchNode sn = s.top();
			s.pop();

			if (result.size() == sn.level) result.push_back(vector<int>());
			result[sn.level].push_back(sn.node->val);

			// push node
			if (sn.node->right) s.push(SearchNode(sn.node->right, sn.level + 1));
			if (sn.node->left) s.push(SearchNode(sn.node->left, sn.level + 1));
		}

		return result;
	}
};
