#include <stdio.h>
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

class Solution {
private:
	TreeNode* createTree(vector<int>& nums, int left, int right) {
		if (left > right) {
			return NULL;
		}

		int middle = (right + left) / 2;
		TreeNode* root = new TreeNode(nums[middle]);
		root->left = this->createTree(nums, left, middle - 1);
		root->right = this->createTree(nums, middle + 1, right);

		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return this->createTree(nums, 0, nums.size() - 1);
	}
};
