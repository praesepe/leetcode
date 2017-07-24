class Solution {
 public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root) {
		std::vector<std::vector<int>> result = {};
		std::queue<std::pair<int, TreeNode*>> q({{1, root}});
		int height = 2;
		std::vector<int> v;

		while (!q.empty()) {
			int h = q.front().first;
			TreeNode* t = q.front().second;

			if (h == height) {
				result.push_back(v);
				v.clear();
				height++;
			}

			q.pop();
			if (t) {
				v.push_back(t->val);
				q.push({height, t->left});
				q.push({height, t->right});
			}
		}
		return result;
    }
};
