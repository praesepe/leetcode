class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // sort input numbers
        sort(nums.begin(), nums.end());

        // push an empty array
        vector<vector<int>> result(1, vector<int>());

        // iterative add a number to existing array
        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            for (int j = 0; j < n; j++) {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }

        return result;
    }
};
