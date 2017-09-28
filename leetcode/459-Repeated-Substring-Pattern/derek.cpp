class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        bool result = false;

        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0) {
                continue;
            }

            for (int j = 0; j < n; j++) {
                if (s[j] != s[j % i]) {
                    break;
                }
                if (j == n -1) {
                    result = true;
                }
            }

            if (result) {
                break;
            }
        }

        return result;
    }
};

