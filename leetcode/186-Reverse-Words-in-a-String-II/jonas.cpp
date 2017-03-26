#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution {
private:
	void reverseString(string &s, size_t start, size_t end) {
		char c;
		for(size_t i = start, j = end; i < j; i++, j--) {
			//swap
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
public:
	void reverseWords(string &s) {

		reverseString(s, 0, s.size() - 1);

		size_t start=0, end;

		while (start < s.size()) {
			end = s.find(" ", start) == string::npos ? s.size() - 1 : s.find(" ", start) - 1;

			reverseString(s, start, end);

			start = end + 2;
		}
	}
};


int main()
{
	// testing
	Solution s;

	string str = "this is general purpose";
	s.reverseWords(str);

	cout << str << endl;

}
