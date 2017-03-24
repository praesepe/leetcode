class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> hash;
        int complement;
        for (size_t i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            complement = target - nums[i];

            if (hash.end() != hash.find(complement) && i != hash[complement]) {
                return vector<int> {(int)i, (int)hash[complement]};
            }
        }
        throw std::invalid_argument("Solution not found");
    }
};
