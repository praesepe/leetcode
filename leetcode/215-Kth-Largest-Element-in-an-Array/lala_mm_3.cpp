#include <vector>

using namespace std;

class Solution {
private:
	int find_median_3(vector<int>& nums, int start, int end) {
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

	int grouping(vector<int>& nums, int start, int end) {
		int medianIndex = start;
		for (int i = start; i <= end; i += 3) {
			swap(nums[medianIndex++], nums[this->find_median_3(nums, i, end >= i + 2 ? i + 2 : end)]);
		}

		return medianIndex - 1;
	}

	int partition(vector<int>& nums, int p, int r, int mm) {
		int target = nums[mm];
		swap(nums[mm], nums[r]);

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

	int select_index(vector<int>& nums, int p, int r, int i) {
		if (p == r) return p;

		int group_index = this->grouping(nums, p, r);
		int median_index = this->select_index(nums, p, group_index, (group_index - p + 1) / 2);
		int q = this->partition(nums, p, r, median_index);

		int k = q - p + 1;
		if (k == i) {
			return q;
		} else if (k > i) {
			return this->select_index(nums, p, q - 1, i);
		} else {
			return this->select_index(nums, q + 1, r, i - k);
		}
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		int index = this->select_index(nums, 0, nums.size() - 1, nums.size() - k + 1);

		return nums[index];
	}
};
