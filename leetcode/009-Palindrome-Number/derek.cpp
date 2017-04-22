class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        int div = 1;
        while (x / div >= 10) {
            div *= 10;
        }

        while (x != 0) {
            int l = x / div;
            int r = x % 10;
            if (l != r) return false;
            // chppoing the first and last digit
            x = (x % div) / 10;
            // because removing two digit, we have to divide 'div' by 100
            div /= 100;
        }

        return true;
    }
};
