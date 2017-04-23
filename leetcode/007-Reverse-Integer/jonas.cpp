class Solution {
public:
    int reverse(int x) {
		long long int next = 0;
		int result = 0;
		int mod;

		while (x != 0) {
			mod = x % 10;
			next = (long long)result * 10 + mod;

			if (next > INT_MAX || next < INT_MIN) {
				return 0;
			}

			x = x / 10;
			result = next;
		}

		return result;
    }
};
