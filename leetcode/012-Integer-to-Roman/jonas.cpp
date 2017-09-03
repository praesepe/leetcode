class Solution {
protected:
    std::vector<std::pair<int, std::string>> romans_ = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

public:
    std::string intToRoman(int num) {
        std::string result;
        int i = 0;

        while (num > 0) {
            if (num >= this->romans_[i].first) {
                num -= this->romans_[i].first;
                result += this->romans_[i].second;
            } else {
                i++;
            }
        }
        return result;
    }
};
