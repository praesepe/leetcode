#include <stack>
#include <cstdlib>

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

struct RunStack {
	int stage;
	TreeNode* root;
	int left_depth;
	int right_depth;

	void return_cbk(int depth) {
		switch (this->stage) {
		case 1:
			this->left_depth = depth;
			break;
		case 2:
			this->right_depth = depth;
			break;
		}
	}

	RunStack(TreeNode* root) {
		this->root = root;
		this->stage = 0;
		this->left_depth = 0;
		this->right_depth = 0;
	}
};

class Solution {
private:
	int depth(TreeNode* root) {
		// stage 0
		if (!root) {
			return 0;
		}

		int left_depth = this->depth(root->left);
		// stage 1

		int right_depth = this->depth(root->right);
		// stage 2

		if (left_depth == -1 || right_depth == -1) {
			return -1;
		} else if (1 < abs(left_depth - right_depth)) {
			return -1;
		}

		return 1 + max(left_depth, right_depth);
	}

	void handle_stage_0(stack<RunStack> &s) {
		if (!s.top().root) {
			// backtrace
			s.pop();
			if (s.empty()) {
				return;
			}
			s.top().return_cbk(0);
		} else {
			s.top().stage = 1;
			s.push(RunStack(s.top().root->left));
		}
	}

	void handle_stage_1(stack<RunStack> &s) {
		s.top().stage = 2;
		s.push(RunStack(s.top().root->right));
	}

	bool handle_stage_2(stack<RunStack> &s) {
		int left_depth = s.top().left_depth;
		int right_depth = s.top().right_depth;

		if (1 < abs(left_depth - right_depth)) {
			return false;
		}

		// backtrace
		s.pop();
		if (s.empty()) {
			return true;
		}

		s.top().return_cbk(1 + max(left_depth, right_depth));
		return true;
	}
public:
	bool isBalanced(TreeNode* root) {
		stack<RunStack> s;

		s.push(RunStack(root));

		bool is_bst = true;
		while (!s.empty() && is_bst) {
			switch (s.top().stage) {
			case 0:
				this->handle_stage_0(s);
				break;
			case 1:
				this->handle_stage_1(s);
				break;
			case 2:
				is_bst = this->handle_stage_2(s);
				break;
			}
		}

		return is_bst;
	}
};
