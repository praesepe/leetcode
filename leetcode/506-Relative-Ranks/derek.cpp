class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // build a hash map (score -> index)
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        // sort by descending order
        sort(nums.begin(), nums.end(), std::greater<int>());

        // according to the original position, give his rank
        vector<string> result(nums.size());
        string words[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i = 0; i < nums.size(); i++) {
            int idx = mp[nums[i]];
            if (i < 3) {
                result[idx] = words[i];
            } else {
                result[idx] = to_string(i + 1);
            }
        }

        return result;
    }
};

