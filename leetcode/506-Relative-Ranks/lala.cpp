#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++) {
            int score = nums[i];
            m[score] = i;
        }

        // answer
        vector<string> result(nums.size());
        int rank = 1;
        for (auto itr = m.rbegin(); itr != m.rend(); ++itr) {
            switch (rank) {
            case 1:
                result[itr->second] = "Gold Medal";
                break;
            case 2:
                result[itr->second] = "Silver Medal";
                break;
            case 3:
                result[itr->second] = "Bronze Medal";
                break;
            default:
                result[itr->second] = to_string(rank);
                break;
            }
            rank++;
        }

        return result;
    }
};
