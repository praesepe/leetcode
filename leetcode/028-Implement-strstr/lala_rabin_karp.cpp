#include <string>

using namespace std;
#define BASE 8
#define PRIME 100000004987

class Solution {
public:
	int strStr(string haystack, string needle) {
		// edge case
		if (haystack.size() < needle.size()) {
			return -1;
		}
		// edge case
		if (needle.empty()) {
			return 0;
		}

		// compute hash
		uint64_t patternHash = 0;
		uint64_t searchHash = 0;
		for (size_t i = 0; i < needle.size(); i++) {
			patternHash = ((patternHash << BASE) + needle[i]) % PRIME;
			searchHash = ((searchHash << BASE) + haystack[i]) % PRIME;
		}

		// compute rolling
		uint64_t rolling = 1;
		for (size_t i = 0; i < needle.size() - 1; i++) {
			rolling = (rolling << BASE) % PRIME;
		}

		// main
		for (size_t i = 0; i < haystack.size() - needle.size() + 1; i++) {
			// check match
			if (searchHash == patternHash) {
				bool match = true;
				for (size_t j = 0; j < needle.size(); j++) {
					if (haystack[i + j] != needle[j]) {
						match = false;
						break;
					}
				}
				if (match) return i;
			}

			searchHash = (searchHash + (PRIME << BASE) - haystack[i] * rolling) % PRIME;
			searchHash = ((searchHash << BASE) + haystack[i + needle.size()]) % PRIME;
		}

		return -1;
	}
};

