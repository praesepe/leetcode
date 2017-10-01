class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> row;
        int i, j, preSize;
        
        result.push_back(row);
        for (i = 0;i < nums.size(); i++) {
            preSize = result.size();
            for (j = 0;j < preSize; j++) {
                vector<int> v = result[j];
                v.push_back(nums[i]);
                result.push_back(v);
            }
        }
        
        return result;
    }
};
