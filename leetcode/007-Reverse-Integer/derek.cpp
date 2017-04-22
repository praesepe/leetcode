class Solution {
public:
    int reverse(int x) {
        int maxDiv10 = INT_MAX / 10;
        int maxMod10 = INT_MAX % 10;
        int y = 0;

        while (x != 0) {
            int r = x % 10;
            if (abs(y) > maxDiv10 || (abs(y) == maxDiv10 && r > maxMod10)) {
                return 0;
            }
            y = y * 10 + r;
            x = x / 10;
        }

        return y;
    }
};

