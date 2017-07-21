#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return s[0] == '0' ? 0 : 1;
        /*
         *  ways_2 ways_1
         *  ............. current
         */
        int result;
        int ways_2 = 1, ways_1 = s[0] == '0' ? 0 : 1;
        for (size_t i = 1; i < s.size(); i++) {
            int current = s[i] - '0';
            int num = stoi(s.substr(i - 1, 2));

            result = (current != 0 ? ways_1 : 0) + ((num >= 10 && num <= 26) ? ways_2 : 0);

            ways_2 = ways_1;
            ways_1 = result;
        }
        return result;
    }
};
