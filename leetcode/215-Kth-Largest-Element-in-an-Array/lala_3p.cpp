#include <vector>

using namespace std;

class Solution {
private:
	bool sorted(const vector<int>& nums) {
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				return false;
			}
		}
		return true;
	}

	int find_median_index(vector<int>& nums, int start, int end) {
		if (end - start < 2) {
			return start;
		}

		int mid = start + 1;
		if (nums[end] >= nums[mid]) {
			if (nums[mid] >= nums[start]) {
				return mid;
			} else if (nums[end] >= nums[start]) {
				return start;
			} else {
				return end;
			}
		} else {
			if (nums[end] >= nums[start]) {
				return end;
			} else if (nums[mid] >= nums[start]) {
				return start;
			} else {
				return mid;
			}
		}
	}

	int partition(vector<int>& nums, int p, int r) {
		int median_index = this->find_median_index(nums, p, r);
		int target = nums[median_index];
		swap(nums[median_index], nums[r]);

		int i = p - 1;
		for (int j = p; j < r; j++) {
			if (target >= nums[j]) {
				i = i + 1;
				swap(nums[i], nums[j]);
			}
		}

		swap(nums[i + 1], nums[r]);
		return i + 1;
	}

	int quick_select(vector<int>& nums, int p, int r, int k) {
		// check sorted
		// if (this->sorted(nums)) return nums[k];

		// main
		int q = this->partition(nums, p, r);
		while (q != k) {
			p = q > k ? p : q + 1;
			r = q > k ? q - 1 : r;
			q = this->partition(nums, p, r);
		}

		return nums[k];
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		return this->quick_select(nums, 0, nums.size() - 1, nums.size() - k);
	}
};
