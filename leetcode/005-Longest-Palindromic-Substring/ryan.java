public class Solution {
    public String longestPalindrome(String s) {
        if (s.length() < 2) {
            return s;
        }
        int longestLen = s.length();
        while (longestLen > 1) {
            // check every substring that length == longestLen
            for (int start = 0, tail = longestLen - 1; tail < s.length(); start++, tail++) {
                int left = start;
                int right = tail;
                boolean flag = true;
                while (left < right) {
                    if (s.charAt(left++) != s.charAt(right--)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return s.substring(start, tail + 1);
                }
            }
            longestLen--;
        }
        // for longestLen == 1
        return Character.toString(s.charAt(0));
    }
}