class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // sort input numbers
        sort(nums.begin(), nums.end());

        // we know there are 2^k possibility
        int n = pow(2, nums.size());
        vector<vector<int>> result(n, vector<int>());

        // 1 << n is 2^n
        // each subset equals to an binary integer between 0 .. 2^n - 1
        // 0 -> 000 -> []
        // 1 -> 001 -> [1]
        // 2 -> 010 -> [2]
        // ..
        // 7 -> 111 -> [1,2,3]
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < n; j++) {
                if ((j >> i) & 0x1) {
                    result[j].push_back(nums[i]);
                }
            }
        }

        return result;
    }
};

