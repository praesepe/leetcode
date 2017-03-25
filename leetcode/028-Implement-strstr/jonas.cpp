class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}

		for (size_t i = 0; i < haystack.size(); i++) {
			if (haystack.size() - i < needle.size()) {
				return -1;
			}

			if (haystack.substr(i, needle.size()) == needle) {
				return (int)i;
			}
		}
		return -1;
	}
};
