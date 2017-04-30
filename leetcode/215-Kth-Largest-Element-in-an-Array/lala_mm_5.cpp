#include <vector>

#define GROUPING 5

using namespace std;

class Solution {
private:
	int find_median(vector<int>& nums, int start, int end) {
		for (int i = start; i <= end - 1; i++) {
			bool sorted = true;
			for (int j = i + 1; j <= end; j++) {
				if (nums[i] > nums[j]) {
					swap(nums[i], nums[j]);
					sorted = false;
				}
			}

			if (sorted) break;
		}

		// sort(nums.begin() + start, nums.begin() + end);
		return (end + start) / 2;
	}

	int grouping(vector<int>& nums, int start, int end) {
		int medianIndex = start;
		for (int i = start; i <= end; i += GROUPING) {
			swap(nums[medianIndex++], nums[this->find_median(nums, i, end >= i + GROUPING ? i + GROUPING : end)]);
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
