class Solution {
private:
	bool isSign(char c) {
		return c == '+' || c == '-';
	}

	void normalizeString(string& str) {
		// rtrim
		string::size_type end_pos = str.find_last_not_of(" \t\r\n");
		if (end_pos != string::npos) {
			str = str.substr(0, end_pos + 1);
		}

		// ltrim
		string::size_type start_pos = str.find_first_not_of(" \t\r\n");
		if (start_pos != string::npos) {
			str = str.substr(start_pos);
		}

		// filter invalid tail string
		end_pos = str.find_first_not_of("0123456789", 1);
		if (end_pos != string::npos) {
			str = str.substr(0, end_pos);
		}

		// check sign
		if (!str.empty() && !isdigit(str[0]) && !this->isSign(str[0])) {
			str = "";
		}
	}
public:
	int myAtoi(string str) {
		normalizeString(str);

		if (str.empty()) {
			return 0;
		}

		int result = 0;
		int base = 1;
		bool overflow = false;
		bool hasSign = isSign(str[0]);

		for (int i = str.size() - 1; i >= hasSign ? 1 : 0; i--) {
			int intval = str[i] - '0';
			// intval
			if (intval > intval * base) {
				overflow = true;
				break;
			}
			intval *= base;

			// result;
			if (result > result + intval) {
				overflow = true;
				break;
			}
			result += intval;

			// base
			if (base > base * 10) {
				overflow = true;
				break;
			}
			base *= 10;
		}

		if (overflow) {
			return str[0] == '-' ? INT_MIN : INT_MAX;
		}

		if (hasSign) {
			result *= (str[0] == '-' ? -1 : 1);
		}

		return result;
	}
};
