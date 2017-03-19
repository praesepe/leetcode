class Solution {
public:
	int strStr(string haystack, string needle) {
		for (int i = 0; i <= haystack.size(); i++) {
			for (int j = 0; j <= needle.size(); j++) {
				if (j == needle.size()) {
					return i;
				}

				if (i + j >= haystack.size()) {
					return -1;
				}

				if (haystack[i + j] != needle[j]) {
					break;
				}
			}
		}

		return -1;
	}
};
