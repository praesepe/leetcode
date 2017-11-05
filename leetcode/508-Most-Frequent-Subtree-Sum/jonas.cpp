class Solution {
protected:
    std::unordered_map<int, size_t> map;

public:
    std::vector<int> findFrequentTreeSum(TreeNode* root) {
        std::vector<int> result;
        size_t max = 0;

        getSum(root);

        // find max frequency
        for (const auto m: this->map) {
            max = std::max(max, m.second);
        }

        for (const auto m: this->map) {
            if (m.second == max) {
                result.push_back(m.first);
            }
        }
        return result;
    }

    int getSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = root->val + getSum(root->right) + getSum(root->left);
        if (this->map.find(sum) == this->map.end()) {
            map[sum] = 1;
        } else {
            map[sum]++;
        }
        return sum;
    }
};
