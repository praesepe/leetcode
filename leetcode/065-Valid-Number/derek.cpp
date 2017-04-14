class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        bool is_numeric = false;

        // skip leading white space
        while (i < n && s[i] == ' ') i++;

        // check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        // check integer part
        while (i < n && isdigit(s[i])) {
            is_numeric = true;
            i++;
        }

        // check decimal point
        if (i < n && s[i] == '.') {
            i++;

            // check fractional part
            while (i < n && isdigit(s[i])) {
                is_numeric = true;
                i++;
            }
        }

        // check scientific notation
        if (i < n && s[i] == 'e' && is_numeric) {
            is_numeric = false;
            i++;

            // check sign
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;

            // check exponent part
            while (i < n && isdigit(s[i])) {
                is_numeric = true;
                i++;
            }
        }

        // skip trailing white space
        while (i < n && s[i] == ' ') i++;

        // return result
        return is_numeric && i == n;
    }
};
