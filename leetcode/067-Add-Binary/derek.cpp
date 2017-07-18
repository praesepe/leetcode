class Solution {
public:
	string addBinary(string a, string b) {
		int n = max(a.length(), b.length());

		// fill leading zero
		a = string(n - a.length(), '0') + a;
		b = string(n - b.length(), '0') + b;

		string ans;
		int carry = 0;
		for (int i = n - 1; i >= 0; i--) {
			// add two character with carry
			carry = carry + (a[i] - '0') + (b[i] - '0');
			// calculate remainder
			ans = (char)(carry % 2 + '0') + ans;
			// calculate quotient
			carry /= 2;
		}

		if (carry == 1) {
			ans = '1' + ans;
		}

		return ans;
	}
};
