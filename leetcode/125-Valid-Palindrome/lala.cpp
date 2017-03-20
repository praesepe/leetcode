class Solution {
private:
	bool isTargetChar(char c) {
		return isalnum(c);
	}
public:
	bool isPalindrome(string s) {
		bool result = true;

		int head = 0;
		int tail = s.size() - 1;
		while (true) {
			while (!this->isTargetChar(s[head])) head++;
			while (!this->isTargetChar(s[tail])) tail--;
			if (tail < head) {
				break;
			}

			if (tolower(s[tail]) != tolower(s[head])) {
				result = false;
				break;
			}

			head++;
			tail--;
		}

		return result;
	}
};
