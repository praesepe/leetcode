#include <queue>
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
		queue<SearchNode> q;

		vector<vector<int>> result;
		if (root) q.push(SearchNode(root, 0));
		while (!q.empty()) {
			SearchNode& sn = q.front();

			if (result.size() == sn.level) result.push_back(vector<int>());
			result[sn.level].push_back(sn.node->val);

			// push node
			if (sn.node->left) q.push(SearchNode(sn.node->left, sn.level + 1));
			if (sn.node->right) q.push(SearchNode(sn.node->right, sn.level + 1));

			q.pop();
		}

		return result;
	}
};
