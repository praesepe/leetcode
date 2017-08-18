#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string tens_case(int num) {
        int tens = num / 10;
        int units = num % 10;

        string result = "";
        if (tens != 0)  result += this->mapping[tens * 10];
        if (units != 0) result += " " + this->mapping[units];

        return result;
    }

    string normal_case(int num, int divisor) {
        int times = num / divisor;
        int remain = num % divisor;

        string result = "";
        if (times != 0)  result += this->convert(times) + " " + this->mapping[divisor];
        if (remain != 0) result += " " + this->convert(num - times * divisor);

        return result;
    }

    string convert(int num) {
        if (num >= 1000000000) return this->normal_case(num, 1000000000);
        if (num >= 1000000)    return this->normal_case(num, 1000000);
        if (num >= 1000)       return this->normal_case(num, 1000);
        if (num >= 100)        return this->normal_case(num, 100);
        if (num >= 20)         return this->tens_case(num);

        return this->mapping[num];
    }
public:
    Solution() {
        this->mapping = {
            {0, "Zero"},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"},
            {100, "Hundred"},
            {1000, "Thousand"},
            {1000000, "Million"},
            {1000000000, "Billion"},
        };
    }

    string numberToWords(int num) {
        return this->convert(num);
    }
private:
    unordered_map<int, string> mapping;
};
