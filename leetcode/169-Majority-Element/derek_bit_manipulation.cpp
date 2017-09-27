class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        vector<int> count(32, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    count[j]++;
                }
            }
        }

        for (int i = 0; i < 32; i++) {
            if (count[i] > nums.size() / 2) {
                result += (1 << i);
            }
        }

        return result;
    }
};
