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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> s;
		TreeNode *ptr = root;

		while (!s.empty() || ptr) {
			if (ptr) {
				s.push(ptr);
				ptr = ptr->left;
			} else {
				result.push_back(s.top()->val);
				ptr = s.top()->right ? s.top()->right : NULL;
				s.pop();
			}
		}

		return result;
	}
};
