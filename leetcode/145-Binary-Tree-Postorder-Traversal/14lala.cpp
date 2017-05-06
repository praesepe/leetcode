#include <stack>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.a
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root) return {};

		stack<TreeNode*> s1, s2;

		s1.push(root);
		while (!s1.empty()) {
			TreeNode* s1top = s1.top();
			s1.pop();
			s2.push(s1top);

			TreeNode* s2top = s2.top();
			if (s2top->left) s1.push(s2top->left);
			if (s2top->right) s1.push(s2top->right);
		}

		vector<int> result;
		while (!s2.empty()) {
			TreeNode* current = s2.top();
			s2.pop();

			result.push_back(current->val);
		}
		return result;
	}
};
