class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 0) {
                nums[w++] = nums[r];
            }
        }

        for (; w < nums.size(); w++) {
            nums[w] = 0;
        }
    }
};
