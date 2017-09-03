class Solution {
protected:
    std::unordered_map<char, int> romans_ = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };

    std::vector<std::pair<std::string, int>> diff_ = {
        {"CM", 200},
        {"CD", 200},
        {"XC", 20},
        {"XL", 20},
        {"IX", 2},
        {"IV", 2}
    };

public:
    int romanToInt(std::string s) {
        int sum = 0;
        for (auto d: this->diff_) {
            if (s.find(d.first) != std::string::npos) {
                sum -= d.second;
            }
        }

        for (auto c: s) {
            sum += this->romans_[c];
        }

        return sum;
    }
};
