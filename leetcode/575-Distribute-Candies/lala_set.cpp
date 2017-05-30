#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> s;

		int result = 0;
		for (const auto candy : candies) {
			if (s.find(candy) == s.end()) {
				result++;
				s.insert(candy);
			}
		}

		int limit = candies.size() / 2;
		return result > limit ? limit : result;
	}
};
