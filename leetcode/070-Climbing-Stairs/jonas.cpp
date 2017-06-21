class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
			return n;
		}

		int climb_one = 2;
		int climb_two = 1;
		int total;

		for (int i = 3; i <= n; i++) {
			total = climb_one + climb_two;
			climb_two = climb_one;
			climb_one = total;
		}

		return total;
    }
};
