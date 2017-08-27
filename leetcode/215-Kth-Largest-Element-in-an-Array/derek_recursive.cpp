#include <vector>
#include <iostream>

using namespace std;

int count = 0;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, 0, nums.size() - 1, k-1);
    }

	int partition(vector<int>& nums, int left, int right) {
		int i = left - 1;
		for (int j = left; j < right; j++) {
			if (nums[j] > nums[right]) {
				swap(nums[++i], nums[j]);
			}
		}
		swap(nums[++i], nums[right]);
		return i;
	}

    int quicksort(vector<int>& nums, int left, int right, int k) {
		if (left == right) {
			return nums[left];
		}

		int pivot = partition(nums, left, right);

		if (k == pivot) {
			return nums[k];
		}

		// find left part
		if (k < pivot) {
			return quicksort(nums, left, pivot - 1, k);
		// find right part
		} else {
			return quicksort(nums, pivot + 1, right, k);
		}
    }
};

int main() {
	vector<int> nums = {3, 3, 3, 3, 4, 3, 3, 3, 3};

	Solution slt;
	int v = slt.findKthLargest(nums, 9);
	cout << v << endl;

	return 0;
}
