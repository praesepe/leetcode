class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		quicksort(nums, 0, nums.size() - 1);

		int sum = 0;
		for (int i = 0; i < nums.size(); i+=2) {
			sum += min(nums[i], nums[i+1]);
		}

		return sum;
    }

	void quicksort(vector<int>& nums, int left, int right)
	{
		if (left < right) {
			int pivot = partition(nums, left, right);
			quicksort(nums, left, pivot - 1);
			quicksort(nums, pivot + 1, right);
		}
	}

	int partition(vector<int>& nums, int left, int right)
	{
		int x  = nums[right];
		int i = left - 1;
		for (int j = left; j <= right - 1; j++) {
			if (nums[j] <= x) {
				i++;
				swap(nums[i], nums[j]);
			}
		}
		i++;
		swap(nums[i], nums[right]);

		return i;
	}
};
