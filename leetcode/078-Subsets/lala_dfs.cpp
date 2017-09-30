#include <vector>

using namespace std;
class Solution {
private:
    void traverse(vector<vector<int>> &answers, vector<int> &nums, vector<int> current, int offset) {
        if (offset != -1) current.push_back(nums[offset]);

        answers.push_back(current);
        for (int i = offset + 1; i < nums.size(); i++) {
            this->traverse(answers, nums, current, i);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answers;

        this->traverse(answers, nums, {}, -1);
        return answers;
    }
};
