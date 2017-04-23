class Solution {
public:
    bool isNumber(string s) {
        bool blStart           = false;
        bool blEnd             = false;
        bool blPoint           = false;
        bool blScience         = false;
        bool blSign            = false;

        for (size_t i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case ' ':
                    blEnd = (blStart || blPoint || blSign) ? true : false;
                    break;
                case '.':
                    if (blEnd || blScience || blPoint) {
                        return false;
                    }
                    blPoint = true;
                    break;
                case 'e':
                case 'E':
                    if (blEnd || blScience || !blStart) {
                        return false;
                    }
                    blScience = true;
                    blStart   = false;
                    blSign    = false;
					blPoint   = false;
                    break;
                case '-':
                case '+':
                    if (blEnd || blSign || blStart || blPoint) {
                        return false;
                    }
                    blSign = true;
                    break;
                default:
                    if (!isdigit(s[i])) {
                        return false;
                    }
                    if (blEnd) {
                        return false;
                    }
                    blStart = true;
            }
        }

        if (!blStart) {
            return false;
        }
        return true;
    }
};
