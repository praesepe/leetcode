class Solution {
private:
	void trimString(string &s) {
		// rtrim
		string::size_type end_pos = s.find_last_not_of(" \t\r\n");
		if (end_pos != string::npos) {
			s = s.substr(0, end_pos + 1);
		} else {
			s.clear();
		}

		// ltrim
		string::size_type start_pos = s.find_first_not_of(" \t\r\n");
		if (start_pos != string::npos) {
			s = s.substr(start_pos);
		}
	}


	bool checkBase(string s) {
		if (s.empty()) {
			return false;
		}

		bool result = true;
		bool hasDot = false;
		for (int i = 0; i < s.size() && result; i++) {
			if (isdigit(s[i])) {
				continue;
			}

			if (s[i] == '.') {
				if (hasDot) {
					result = false;
				} else {
					result = (i > 0 && isdigit(s[i - 1])) ||
						((i + 1 < s.size()) && isdigit(s[i + 1]));
				}

				hasDot = true;
			} else if (s[i] == '+') {
				result = i == 0 && s.size() > 1;
			} else if (s[i] == '-') {
				result = i == 0 && s.size() > 1;
			} else {
				result = false;
			}
		}

		return result;
	}

	bool checkExponential(string s) {
		if (s.empty()) {
			return false;
		}

		bool result = true;
		for (int i = 0; i < s.size() && result; i++) {
			if (isdigit(s[i])) {
				continue;
			}

			if (s[i] == '+') {
				result = i == 0 && s.size() > 1;
			} else if (s[i] == '-') {
				result = i == 0 && s.size() > 1;
			} else {
				result = false;
			}
		}

		return result;
	}
public:
	bool isNumber(string s) {
		bool result = false;

		this->trimString(s);
		string::size_type pos = s.find("e");
		// case 1: base
		if (pos == string::npos) {
			result = this->checkBase(s);
			// case 2: exponential
		} else {
			result = this->checkBase(s.substr(0, pos)) &&
				this->checkExponential(s.substr(pos + 1));
		}

		return result;
	}
};
