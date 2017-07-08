class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right && nums[left] == nums[right]) {
            right--;
        }

        while (left < right) {
            if (nums[left] < nums[right]) {
                break;
            }

            int middle = (left + right) / 2;
            if (nums[left] <= nums[middle]) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return nums[left];
    }
};
