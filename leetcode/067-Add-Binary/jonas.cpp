class Solution {
public:
    string addBinary(string a, string b) {
		string result = "";
        int i = a.size() - 1;
		int j = b.size() - 1;
		int carry = 0;

		while (i >= 0 || j >= 0 || carry > 0) {
			carry += i >= 0 ? a[i--] - '0' : 0;
			carry += j >= 0 ? b[j--] - '0' : 0;
			result = std::to_string(carry%2) + result;
			carry /= 2;
		}
		return result;
    }
};
