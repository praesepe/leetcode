#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry == 1) {
            vector<int> newDigits(digits.size() + 1, 0);
            newDigits[0] = 1;
            return newDigits;
        }

        return digits;
    }
};
