// Copyright 2017
#include <iostream>
#include <vector>
#include <string>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Item {
	TreeNode *node;
	std::string path;
	Item(TreeNode* n, std::string s) : node(n), path(s) {}
};


class Solution {
 public:
	std::vector<std::string> binaryTreePaths(TreeNode* root) {
		std::stack<Item> stack;
		std::vector<std::string> ans;

		stack.push(Item(root, ""));

		while (!stack.empty()) {
			Item item = stack.top();
			stack.pop();

			if (!item.node) {
				continue;
			}

			std::string path = item.path.empty() ? "" : item.path + "->";
			path += std::to_string(item.node->val);

			if (!item.node->left && !item.node->right) {
				ans.push_back(path);
			} else {
				stack.push(Item(item.node->left, path));
				stack.push(Item(item.node->right, path));
			}
		}
		return ans;
    }
};


int main() {
	Solution s;
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(4);

	a->left = b;
	b->right = c;
	b->left = d;

	std::vector<std::string> ans = s.binaryTreePaths(a);

	for (auto s: ans) {
		std::cout << s << std::endl;
	}

	return 0;
}
