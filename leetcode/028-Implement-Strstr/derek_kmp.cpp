class Solution {
public:
    int strStr(string haystack, string needle) {
        // check edge case
        if (haystack.length() < needle.length()) {
            return -1;
        }
        if (needle.length() == 0) {
            return 0;
        }
        
        vector<int> failure = getFailure(needle);

        int i = 0;
        for (int j = 0; j < haystack.length(); j++) {
            while (i > 0 && needle[i] != haystack[j]) {
                i = failure[i - 1];
            }
            
            if (needle[i] == haystack[j]) {
                i++;                
            }

            if (i == needle.length()) {
                return j - i + 1;
            }
        }

        return -1;        
    }
private:
    vector<int> getFailure(string needle) {

        // ababad
        // 001230
        //
        //       j
        // ababa d
        //   aba bad
        //       i
        //
        //       j
        // ababa d
        //     a babad
        //       i

        vector<int> failure(needle.size(), 0);

        int i = 0;
        for (int j = 1; j < needle.length(); j++) {
            while (i > 0 && needle[i] != needle[j]) {
                i = failure[i-1];
            }

            if (needle[i] == needle[j]) {
                i++;
                failure[j] = i;
            } else {
                failure[j] = 0;
            }
        }

        return failure;
    }
};
