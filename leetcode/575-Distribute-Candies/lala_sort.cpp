#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		sort(candies.begin(), candies.end());

		int result = 0;
		int previous_candy = -100001;
		for (const auto candy : candies) {
			if (candy != previous_candy) {
				result++;
				previous_candy = candy;
			}
		}

		int limit = candies.size() / 2;
		return result > limit ? limit : result;
	}
};
