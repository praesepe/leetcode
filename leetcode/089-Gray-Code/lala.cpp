#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> result(1 << n);
            result[0] = 0;

            for (int i = 1; i <= n; i++) {
                int times = 1 << i;
                for (int j = times / 2; j < times; j++) {
                    result[j] = result[times - j - 1] | (1 << (i - 1));
                }
            }

            return result;
        }
};
