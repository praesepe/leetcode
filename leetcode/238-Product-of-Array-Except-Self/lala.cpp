#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);

        int left = 1;
        for (int i = 0; i < size; i++) {
            result[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};
