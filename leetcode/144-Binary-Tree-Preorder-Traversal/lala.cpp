#include <vector>
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

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> s;

		s.push(root);
		while (!s.empty()) {
			TreeNode* current = s.top();
			s.pop();
			if (!current) {
				continue;
			}

			result.push_back(current->val);
			s.push(current->right);
			s.push(current->left);
		}

		return result;
	}
};
