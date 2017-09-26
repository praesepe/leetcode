class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (auto num: nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (first > num && num > second) {
                third = second;
                second = num;
            } else if (second > num && num >third) {
                third = num;
            }
        }

        if (third != LONG_MIN) {
            return third;
        } else {
            return first;
        }
    }
};

