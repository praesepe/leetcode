class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() < b.length()) {
			return addBinary(b, a);
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = b.length(); i < a.length(); i++) {
			b += '0';
		}

		int carry = 0;
		string result;

		for (int i = 0; i < a.length(); i++) {
			if (carry == 0) {
				if (a[i] == '0' && b[i] == '0') {
					result += '0';
					carry = 0;
				} else if (a[i] == '0' && b[i] == '1') {
					result += '1';
					carry = 0;
				} else if (a[i] == '1' && b[i] == '0') {
					result += '1';
					carry = 0;
				} else {
					result += '0';
					carry = 1;
				}
			} else {
				if (a[i] == '0' && b[i] == '0') {
					result += '1';
					carry = 0;
				} else if (a[i] == '0' && b[i] == '1') {
					result += '0';
					carry = 1;
				} else if (a[i] == '1' && b[i] == '0') {
					result += '0';
					carry = 1;
				} else {
					result += '1';
					carry = 1;
				}
			}
		}

		if (carry == 1) {
			result += '1';
		}

		reverse(result.begin(), result.end());
		return result;
	}
};
