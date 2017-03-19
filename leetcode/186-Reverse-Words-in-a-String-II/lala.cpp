#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
	void reverse(string& s, string::size_type start, string::size_type end) {
		for (string::size_type i = 0; i < (end - start + 1) / 2; i++) {
			this->swap(s, start + i, end - i);
		}
	}

	void swap(string& s, string::size_type idx1, string::size_type idx2) {
		char tmp = s[idx1];
		s[idx1] = s[idx2];
		s[idx2] = tmp;
	}
public:
	void reverseWords(string &s) {
		// reverse
		this->reverse(s, 0, s.size() - 1);

		// reverse by space
		string::size_type end_pos = 0, start_pos = 0;
		end_pos = s.find(' ', start_pos);
		while (start_pos < s.size()) {
			end_pos = s.find(' ', start_pos);
			end_pos = end_pos == string::npos ? s.size() : end_pos;

			reverse(s, start_pos, end_pos - 1);
			start_pos = end_pos + 1;
		}
	}
};

int main() {
	Solution s;
	string str = "lala is buggy";

	s.reverseWords(str);
	cout << str << endl;
	return 0;
}

