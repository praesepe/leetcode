class Solution {
public:
    int myAtoi(string str) {

        int i = 0, n = str.size();
        int sign = 1, sum = 0;
        int max_div_10 = INT_MAX / 10;
        int max_mod_10 = INT_MAX % 10;

        // skip leading space
        while (i < n && str[i] == ' ') i++;

        // deal with sign
        if (i < n && str[i] == '+') {
            i++;
        } else if (i < n && str[i] == '-') {
            sign = -1;
            i++;
        }

        // deal with digit character
        while (i < n && isdigit(str[i])) {
            int digit = str[i] - '0';
            // check overflow
            if (sum > max_div_10 || sum == max_div_10 && digit > max_mod_10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            // accumulate
            sum = sum * 10 + digit;
            i++;
        }

        return sign * sum;
    }
};
