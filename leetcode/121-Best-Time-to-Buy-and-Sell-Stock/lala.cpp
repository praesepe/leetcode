#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, low = INT_MAX;

        for (const auto price : prices) {
            if (low > price) {
                low = price;
            } else {
                result = max(result, price - low);
            }
        }

        return result;
    }
};
