class Solution {
private:
    vector<int> compute_failure_table(string needle) {
        vector<int> failure(needle.size(), 0);

        int j = 0;
        for (int i = 1; i< failure.size(); i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = failure[j - 1];
            }

			if (needle[i] == needle[j]) {
				j++;
				failure[i] = j;
			}
		}

        return failure;
    }
public:
    int strStr(string haystack, string needle) {
        //
        if (haystack.size() < needle.size()) {
            return -1;
        }
        if (needle.empty()) {
            return 0;
        }

		// compute failure table
		int result = -1;
		vector<int> failure = this->compute_failure_table(needle);

		// search
		int j = 0;
		for (int i = 0; i < haystack.size(); i++) {
			while (j > 0 && haystack[i] != needle[j]) {
				j = failure[j - 1];
			}

            if (haystack[i] == needle[j]) {
                j++;
            }

			if (j == needle.size()) {
				result = i - needle.size() + 1;
				break;
			}
		}

        return result;
    }
};
