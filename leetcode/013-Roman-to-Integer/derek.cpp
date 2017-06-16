class Solution {
public:
    int romanToInt(string s) {

        map<char, int> mp = {
            {'I',    1},
            {'V',    5},
            {'X',   10},
            {'L',   50},
            {'C',  100},
            {'D',  500},
            {'M', 1000}
        };

        int prev = 0;
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = mp[s[i]];
            total += (curr > prev) ? (curr - 2 * prev) : curr;
            prev = curr;
        }

        return total;
    }
};
