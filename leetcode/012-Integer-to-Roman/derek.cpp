class Solution {
public:
    string intToRoman(int num) {
        int values[] = {
            1000, 900, 500, 400,
             100,  90,  50,  40,
              10,   9,   5,   4,
               1
        };

        string symbols[] = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV",
            "I"
        };

        string roman;
        int i = 0;
        while (num > 0) {
            int k = num / values[i];
            for (int j = 0; j < k; j++) {
                roman += symbols[i];
                num -= values[i];
            }
            i++;
        }

        return roman;
    }
};
