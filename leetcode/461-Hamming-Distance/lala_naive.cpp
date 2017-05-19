class Solution {
public:
	int hammingDistance(int x, int y) {
		int target = x ^ y;

		int result = 0;
		while (target) {
			target = (target & target - 1);
			result++;
		}

		return result;
	}
};
