public class Solution {
    public int reverse(int x) {
        long l = 0;
        while (x != 0) {
            l = l * 10 + x % 10;
            x /= 10;
            if (l > Integer.MAX_VALUE || l < Integer.MIN_VALUE) {
                return 0;
            }
        }
        return (int) l;
    }
}