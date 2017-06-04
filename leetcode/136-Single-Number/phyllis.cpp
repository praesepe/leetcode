class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rv = 0;
        for (int i = 0; i<nums.size(); i++)
        {
        	rv ^=nums[i];
        }
        return rv;
    }
};
