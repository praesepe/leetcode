#include <stdio.h>
#include <unordered_map>

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
	int getCount(TreeNode* root) {
		if (!root) return 0;

		// check cache
		unordered_map<TreeNode*, uint32_t>::iterator itr = this->_cache.find(root);
		if (itr != this->_cache.end()) return itr->second;

		// count
		int totalCount = 1 + this->getCount(root->left) + this->getCount(root->right);

		// set cache
		this->_cache.insert(make_pair(root, totalCount));
		return totalCount;
	}

	int solve(TreeNode* root, int k) {
		int target = 1 + this->getCount(root->left);
		if (k == target) {
			return root->val;
		} else if (k > target) {
			return this->solve(root->right, k - target);
		}

		return this->solve(root->left, k);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		this->_cache.clear();
		return this->solve(root, k);
	}
private:
	unordered_map<TreeNode*, uint32_t> _cache;
};
