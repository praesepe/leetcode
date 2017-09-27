class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        unordered_map<int, int> count;

        for (auto num: nums) {
            count[num]++;
            if (count[num] > nums.size() / 2) {
                result = num;
                break;
            }
        }

        return result;
    }
};
