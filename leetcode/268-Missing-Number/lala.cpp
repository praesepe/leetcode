#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected = (nums.size() + 1) * nums.size() / 2;
        for (const auto num : nums) expected -= num;

        return expected;
    }
};
