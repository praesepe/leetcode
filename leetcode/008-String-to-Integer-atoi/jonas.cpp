class Solution {
public:
	int myAtoi(string str) {
		size_t pos = str.find_first_not_of(" ");
		bool is_positive = true;
		int result = 0;
		int digit;

		if (pos == string::npos) {
			goto End;
		}


		switch(str[pos]) {
			case '-':
				is_positive = false;
				pos++;
				break;
			case '+':
				is_positive = true;
				pos++;
				break;
			default:
				break;
		}

		while (pos < str.size()) {
			// Ensure it's legal digit character
			if (str[pos] < '0' || str[pos] > '9') {
				break;
			}

			digit = str[pos] - '0';

			// Ensure it won't overflow
			if (is_positive && result > (INT_MAX - digit) / 10) {
				result = INT_MAX;
				goto End;
			} else if (!is_positive && -result < (INT_MIN + digit) / 10) {
				result = INT_MIN;
				goto End;
			}

			result = result*10 + (str[pos] - '0');
			cout << result << endl;
			pos++;
		}

		result = is_positive ? result : -result;
	End:
		return result;
	}
};
