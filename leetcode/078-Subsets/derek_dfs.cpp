class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;

        sort(nums.begin(), nums.end());
        dfs(nums, 0, sub, result);

        return result;
    }

    void dfs(vector<int>& nums, int start, vector<int> sub, vector<vector<int>>& result) {
        result.push_back(sub);

        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, result);
            sub.pop_back();
        }
    }
};
