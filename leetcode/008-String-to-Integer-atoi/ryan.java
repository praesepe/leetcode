public class Solution {
    public int myAtoi(String str) {
        if (str.length() == 0) {
            return 0;
        }
        char[] strs = str.toCharArray();
        int idx = 0;
        // find first nonspec character
        while (strs[idx] == ' ') {
            idx++;
        }
        // check sign
        boolean isNegative = false;
        if (strs[idx] == '-' || strs[idx] == '+') {
            isNegative = strs[idx++] == '-';
        }
        // string to integer
        long result = 0;
        while (idx < strs.length && Character.isDigit(strs[idx])) {
            result = 10 * result + (strs[idx++] - '0') * (isNegative ? -1 : 1);
            if (result > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (result < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
        }
        return (int) result;
    }
}