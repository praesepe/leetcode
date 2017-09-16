#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty()) {
                if (nums[i] < nums[dq.back()]) break;
                dq.pop_back();
            }

            dq.push_back(i);
            if (i + 1 >= k) result.push_back(nums[dq.front()]);
            if (dq.front() <= i + 1 - k) dq.pop_front();
        }

        return result;
    }
};
