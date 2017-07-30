public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length();
        int j = b.length();
        int temp = 0;
        while (i > 0 || j > 0) {
            int sum = temp;
            if (i > 0) {
                sum += a.charAt(--i) - '0';
            }
            if (j > 0) {
                sum += b.charAt(--j) - '0';
            }
            sb.insert(0, sum % 2);
            temp = sum / 2;
        }
        if (temp != 0) {
            sb.insert(0, temp);
        }
        return sb.toString();
    }
}