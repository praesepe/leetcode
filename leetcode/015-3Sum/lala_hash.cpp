#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // O(N^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        unordered_map<int, int> m;
        for (const auto num : nums) m[num]++;

        for (auto itr1 = m.begin(); itr1 != m.end(); ++itr1) {
            for (auto itr2 = m.begin(); itr2 != m.end(); ++itr2) {
                int target = -(itr1->first + itr2->first);
                // check range
                if (!(itr1->first <= target && target <= itr2->first)) continue;

                // check target
                if (m.find(target) == m.end()) continue;

                // check nums
                int required = 1;
                required += target == itr1->first ? 1 : 0;
                required += target == itr2->first ? 1 : 0;
                if (m[target] >= required) result.push_back({ itr1->first, target, itr2->first });
            }
        }

        return result;
    }
};
