#include <cstdio>
#include <iostream>

using namespace std;

#define base 256
#define prime 101

class Solution {
public:
    int strStr(string haystack, string needle) {
		int n = haystack.length();
		int m = needle.length();

		if (m == 0) {
			return 0;
		}

		// The value of h would be "pow(d, m-1) % prime"
		int h = 1;
		for (int i = 0; i < m - 1; i++) {
			h = (h * base) % prime;
		}

		// Calculate the hash value of first window of text and pattern
		int text_hash = 0;
		int patt_hash = 0;
		for (int i = 0; i < m; i++) {
			text_hash = (text_hash * base + haystack[i]) % prime;
			patt_hash = (patt_hash * base + needle[i]) % prime;
		}

		//
		for (int i = 0; i <= n - m; i++) {
			// Check if the current sliding window of text and pattern have same hash values
			if (text_hash == patt_hash) {
				// Check if all characters are same or it's a SPURIOUS HIT !
				for (int j = 0; j < m; j++) {
					if (haystack[i + j] != needle[j]) {
						break;
					}
					if (j == m - 1) {
						return i;
					}
				}
			}
			// Calculate hash value for next window of text: Removing Old-high oder digit
			// adding new-low order digit
			if (i != n - m) {
				text_hash = ((text_hash - haystack[i] * h) * base + haystack[i + m]) % prime;
				// We might get negative value of t, converting it to positive
				if (text_hash < 0) {
					text_hash += prime;
				}
			}
		}

		return -1;
    }
};


int main()
{
	string haystack = "mississippi";
	string needle = "issip";

	Solution slt;
	int pos = slt.strStr(haystack, needle);
	cout << pos << endl;

	return 0;
}
