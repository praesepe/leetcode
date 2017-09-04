class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        list<int> ls;

        for (int i = 0; i < nums.size(); i++) {
            // remove numbers out of range k
            if (!ls.empty() && ls.front() == i - k) {
                ls.pop_front();
            }

            // remove smaller numbers in k range as they are useless
            while (!ls.empty() && nums[ls.back()] < nums[i]) {
                ls.pop_back();
            }
            ls.push_back(i);

            // find front element is the index of the max number in slide window
            if (i >= k - 1) {
                result.push_back(nums[ls.front()]);
            }
        }

        return result;
    }
};
