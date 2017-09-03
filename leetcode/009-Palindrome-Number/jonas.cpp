class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;

        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return x == rev || x == rev/10;
    }
};
