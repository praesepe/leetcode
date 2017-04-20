class Solution {
public:
    int reverse(int x) {
		int result = 0;
		int mod, next;

		while (x != 0) {
			mod = x % 10;
			next = result * 10 + mod;

			// Ensure it doesn't overflow
			if ( (next - mod) / 10 != result) {
				return 0;
			}
			x = x / 10;
			result = next;
		}

		return result;
    }
};
