#include <vector>
#include <string>
#include <sstream>

using namespace std;
/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void traverse(TreeNode* root, vector<string>& result, string path) {
		stringstream ss;
		ss << path << "->" << root->val;

		// leaf
		if (!root->left && !root->right) {
			// since it will always add the "->" to the head
			result.push_back(ss.str().substr(2));
			return;
		}

		if (root->left) traverse(root->left, result, ss.str());
		if (root->right) traverse(root->right, result, ss.str());
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return {};

		vector<string> result;
		traverse(root, result, "");

		return result;
	}
};
