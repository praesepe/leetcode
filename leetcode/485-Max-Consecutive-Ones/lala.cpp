#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int current = 0;
        for (const auto num : nums) {
            if (num == 1) {
                current++;
            } else {
                result = max(result, current);
                current = 0;
            }
        }
        return max(result, current);
    }
};
