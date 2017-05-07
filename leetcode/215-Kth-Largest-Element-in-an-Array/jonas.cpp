class Solution {
protected:
	int partition(vector<int>& nums, int low, int high) {
		int i = low;

		for (int n = low; n < high; n++) {
			if (nums[n] > nums[high]) {
				swap(nums[i++], nums[n]);
			}
		}
		swap(nums[i], nums[high]);
		return i;
	}

	int quickSelect(vector<int>& nums, int low, int high, int k) {
		if (low == high) {
			return nums[low];
		}


		int pivot = partition(nums, low, high);

		if (pivot == k) {
			return nums[k];
		} else if (pivot > k) {
			return quickSelect(nums, low, pivot-1, k);
		} else {
			return quickSelect(nums, pivot+1, high, k);
		}
	}
public:
    int findKthLargest(vector<int>& nums, int k) {
		return quickSelect(nums, 0, nums.size()-1, k-1);
    }
};
