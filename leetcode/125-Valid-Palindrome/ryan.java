public class Solution {
    public boolean isPalindrome(String s) {
        if (s.isEmpty()) {
            return true;
        }
        int left = 0;
        int right = s.length() - 1;
        while (right > left) {
            char left_c = s.charAt(left);
            char right_c = s.charAt(right);
            if (!Character.isLetterOrDigit(right_c)) {
                right--;
            } else if (!Character.isLetterOrDigit(left_c)) {
                left++;
            } else {
                if(Character.toLowerCase(left_c) != Character.toLowerCase(right_c)) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
}