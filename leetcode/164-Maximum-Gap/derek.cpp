class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}

		radixsort(nums);

		int diff = 0;
		for (int i = 1; i < nums.size(); i++) {
			diff = max(nums[i] - nums[i-1], diff);
		}

		return diff;
    }

	void radixsort(vector<int> &nums)
	{
		// find the max value
		int maxValue = nums[0];
		for (int i = 0; i < nums[i]; i++) {
			if (nums[i] > maxValue) {
				maxValue = nums[i];
			}
		}

		// run the loop for each of the decimal places
		int exp = 1;
		queue<int> count[10];

		while (maxValue / exp > 0) {
			// count the occurences in this decimal digit
			for (int i = 0; i < nums.size(); i++) {
				count[nums[i] / exp % 10].push(nums[i]);
			}

			// reorder the numbers
			int pos = 0;
			vector<int> tmp;
			for (int i = 0; i < 10; i++) {
				while (!count[i].empty()) {
					tmp.push_back(count[i].front());
					count[i].pop();
				}
			}

			// copy back to the original
			for (int i = 0; i < nums.size(); i++) {
				nums[i] = tmp[i];
			}

			// next digit
			exp *= 10;
		}
	}
};
