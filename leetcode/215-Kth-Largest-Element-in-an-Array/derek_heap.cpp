#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
	int left(int i) {
		return i * 2 + 1;
	}

	int right(int i) {
		return i * 2 + 2;
	}

	void maxHeapify(vector<int>& nums, int i) {
		int largest = i;
		int l = left(i);
		int r = right(i);
		if (l < heap_size && nums[l] > nums[largest]) {
			largest = l;
		}
		if (r < heap_size && nums[r] > nums[largest]) {
			largest = r;
		}
		if (largest != i) {
			swap(nums[largest], nums[i]);
			maxHeapify(nums, largest);
		}
	}

	void buildMaxHeap(vector<int>& nums) {
		heap_size = nums.size();
		for (int i = heap_size/2 - 1; i >= 0; i--) {
			maxHeapify(nums, i);
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		int result;

		// O(n)
		buildMaxHeap(nums);

		// O(k*lg(n))
		for (int i = 0; i < k; i++) {
			result = nums[0];
			swap(nums[0], nums[heap_size - 1]);
			heap_size--;
			maxHeapify(nums, 0);
		}

		return result;
	}

private:
	int heap_size;
};

int main() {
	vector<int> nums = {3, 2, 1, 5, 6, 4};
	int k = 6;

	Solution slt;
	int v = slt.findKthLargest(nums, k);
	cout << v << endl;

	for (auto num: nums) {
		printf("%d, ", num);
	}
	printf("\n");

	return 0;
}
