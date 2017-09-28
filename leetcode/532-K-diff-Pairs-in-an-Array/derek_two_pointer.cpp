class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            j = max(j, i + 1);

            while (nums[j] - nums[i] < k) {
                j++;
            }

            if (nums[j] - nums[i] == k) {
                result++;
            }

            while (i < n - 1 && nums[i] == nums[i+1]) {
                i++;
            }
        }

        return result;
    }
};
