#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		// filling leading zero
		if (a.size() > b.size()) {
			b = string(a.size() - b.size(), '0') + b;
		} else if (b.size() > a.size()) {
			a = string(b.size() - a.size(), '0') + a;
		}

		// added
		bool carry = false;
		for (int i = a.size(); i >= 0 ; i--) {
			char sum = (a[i] == b[i]) ?
				(carry ? '1' : '0') :
				(carry ? '0' : '1');

			carry = (a[i] == '1' && b[i] == '1') || (carry && (b[i] == '1' || a[i] == '1'));
			a[i] = sum;
		}

		return carry ? "1" + a : a;
	}
};
