class Solution {
protected:
    int binarySearch(vector<int>& nums, int target, int left, int right)
    {
		if (left > right) {
			return left;
		}

		int middle = (left + right) / 2;

		if (nums[middle] == target) {
			return middle;
		} else if(nums[middle] > target) {
			return binarySearch(nums, target, left, middle-1);
		} else {
			return binarySearch(nums, target, middle+1, right);
		}
    }
public:
    int searchInsert(vector<int>& nums, int target) {
	return binarySearch(nums, target, 0, nums.size()-1);
    }
};
