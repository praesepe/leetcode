class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;

        // number -> frequncy
        unordered_map<int, int> count;
        for (auto num: nums) {
            count[num]++;
        }

        //
        int target1, target2;
        for (auto it: count) {
            // check repeat number
            if (k == 0 && count[it.first] >= 2) {
                result++;
            }

            // only find target number is larger than self
            if (k > 0 && count.find(it.first + k) != count.end()) {
                result++;
            }
        }

        return result;
    }
};
