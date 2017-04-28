#include <string>

using namespace std;
#define BASE 8
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

		// compute pattern hash
		uint64_t patternHash = 0;
		for (size_t i = 0; i < needle.size(); i++) {
			patternHash = ((patternHash << BASE) | needle[i]);
		}

		//
		int ROLLING = BASE * (needle.size() - 1) > 64 - BASE ?
			64 - BASE :
			BASE * (needle.size() - 1);

		// main
		uint64_t searchHash = 0;
		for (size_t i = 0; i < haystack.size(); i++) {
			// rolling hash
			searchHash = (((((searchHash >> ROLLING) << ROLLING) ^ searchHash) << BASE) | haystack[i]);

			if (i + 1 < needle.size()) continue;
			if (searchHash != patternHash) continue;

			// check match
			bool match = true;
			int startIndex = i - needle.size() + 1;
			for (size_t j = 0; j < needle.size(); j++) {
				if (haystack[startIndex + j] != needle[j]) {
					match = false;
					break;
				}
			}
			if (match) {
				return startIndex;
			}
		}

		return -1;
	}
};
