#include <vector>
#include <iostream>

using namespace std;

int count = 0;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		k--;

		while (true) {
			int pivot = partition(nums, left, right);
			if (k == pivot) {
				break;
			}

			// left part
			if (k < pivot) {
				right = pivot - 1;
			// right part
			} else {
				left = pivot + 1;
			}
		}

		return nums[k];
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
};

int main() {
	vector<int> nums = {3, 3, 3, 3, 4, 3, 3, 3, 3};
	//vector<int> nums = {1, 2, 3, 3, 4, 2, 1, 5, 8};

	Solution slt;
	int v = slt.findKthLargest(nums, 9);
	cout << v << endl;


	for (auto num: nums) {
		printf("%d, ", num);
	}
	printf("\n");

	return 0;
}
