class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> count;
        int max_count = 0;
        traversal(root, count, max_count);

        vector<int> result;
        for (auto it: count) {
            if (it.second == max_count) {
                result.push_back(it.first);
            }
        }

        return result;
    }

    int traversal(TreeNode* root, unordered_map<int, int>& count, int& max_count) {
        if (root == NULL) {
            return 0;
        }

        int sum = root->val;
        sum += traversal(root->left, count, max_count);
        sum += traversal(root->right, count, max_count);
        count[sum]++;

        max_count = max(max_count, count[sum]);

        return sum;
    }
};

