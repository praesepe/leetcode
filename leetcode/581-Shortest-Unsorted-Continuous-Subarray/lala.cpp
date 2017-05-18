#include <vector>

using namespace std;

class Solution {
private:
	int find_tail(vector<int>& nums) {
		int tail = 0;
		int current_max = nums[tail];
		for (size_t i = tail; i < nums.size(); i++) {
			if (nums[i] >= current_max) {
				current_max = nums[i];
			} else {
				tail = i;
			}
		}

		return tail;
	}

	int find_head(vector<int>& nums) {
		int head = nums.size() - 1;
		int current_min = nums[head];
		for (int i = head; i >= 0; i--) {
			if (nums[i] <= current_min) {
				current_min = nums[i];
			} else {
				head = i;
			}
		}

		return head;
	}
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int tail = this->find_tail(nums);
		if (tail == 0) return 0;

		int head = this->find_head(nums);
		return tail - head + 1;
	}
};
