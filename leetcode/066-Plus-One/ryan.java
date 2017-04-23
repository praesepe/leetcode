public class Solution {
    public int[] plusOne(int[] digits) {
        int idx = digits.length - 1;
        while (digits[idx] == 9) {
            digits[idx] = 0;
            idx--;
            if (idx < 0) {
                int[] result = new int[digits.length + 1];
                result[0] = 1;
                return result;
            }
        }
        digits[idx]++;

        return digits;
    }
}