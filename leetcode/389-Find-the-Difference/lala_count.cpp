#include <string>

using namespace std;

#define SIZE 26

class Solution {
public:
	char findTheDifference(string s, string t) {
		int count[SIZE] = {0};

		for (size_t i = 0; i < s.size(); i++) {
			count[s[i] - 'a']++;
		}

		for (size_t i = 0; i < t.size(); i++) {
			count[t[i] - 'a']--;
		}

		for (int i = 0; i < SIZE; i++) {
			if (count[i] == -1) return i + 'a';
		}

		return NULL;
	}
};
